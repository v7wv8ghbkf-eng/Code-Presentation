#include <iostream>
#include <vector>
using namespace std;

// 确认大致的数组范围，防止数组太小、边界太紧从而发生越界
const int N = 6010;

// n个职员（节点总数）
int n;
// h[i]第i号职员的快乐指数
int h[N];
/*-----状态表示f[u][0], f[u][1]-----*/
// 【集合】以u为根的子树中：
//   f[u][0] = u不参加时，该子树能获得的最大快乐值
//   f[u][1] = u参加时，该子树能获得的最大快乐值
int f[N][2];

// 邻接表：children[u]存储u的所有直接下属（子节点）
vector<int> children[N];
// has_father[i]标记i号职员是否有直接上司（用于找根节点）
bool has_father[N];

// 建边函数：a是上司，b是下属，将b加入a的子节点列表
void add(int a, int b)
{
    children[a].push_back(b);
}

// 树形DP（后序遍历）：先递归计算所有子节点，再计算当前节点
void dfs(int u)
{
    // 初始化：
    // u参加 → 先把自己的快乐值算上
    // u不参加 → 初始为0
    f[u][1] = h[u];
    f[u][0] = 0;

    // 遍历u的每一个直接下属（子节点）
    for(int j : children[u])
    {
        // 先递归计算子节点j的子树
        dfs(j);

        /*----- 状态转移 -----*/
        // 1. 如果u不去：儿子可以自由选择去(max)或不去(max)，选大的累加
        f[u][0] += max(f[j][0], f[j][1]);

        // 2. 如果u去：直接上司在场，儿子绝对不能去，只能累加f[j][0]
        f[u][1] += f[j][0];
    }
}

int main()
{
    // 输入职员总数
    cin >> n;

    // 读入每个人的快乐值（编号从1开始）
    for(int i = 1; i <= n; i++)
        cin >> h[i];

    // 读入 n-1 条上下级关系边
    for(int i = 0; i < n - 1; i++)
    {
        int L, K; // 输入格式：L K，表示K是L的直接上司
        cin >> L >> K;

        add(K, L);            // 将L添加为K的下属
        has_father[L] = true; // 标记L有上司
    }

    // 找根节点（大老板）：没有上司的那个人就是整棵树的根
    int root = 1;
    while(has_father[root])
        root++;

    // 从根节点开始树形DP
    dfs(root);

    // 最终答案：大老板去或不去，两种情况取最大值
    cout << max(f[root][0], f[root][1]) << endl;

    return 0;
}
