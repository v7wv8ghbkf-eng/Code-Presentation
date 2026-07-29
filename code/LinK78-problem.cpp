#include<iostream>
using namespace std;

// 确认大致的数组范围，防止数组太小、边界太紧从而发生越界
const int N = 35;

// 二叉树节点个数
int n;
// w[i]第i个节点的分数；root[l][r]区间[l,r]构成子树时得分最高的根节点编号
int w[N], root[N][N];
/*-----状态表示f[l][r]-----*/
// 【集合】中序遍历区间[l,r]内的节点构成的所有二叉树中，最高加分
int f[N][N];

// 前序遍历输出：根据root数组递归输出二叉树的前序遍历
void dfs(int l, int r)
{
    // 空区间，递归边界
    if(l > r) return;

    // 取出当前区间的根节点编号
    int k = root[l][r];
    // 输出根节点（前序遍历：根→左→右）
    cout << k << " ";

    // 递归输出左子树和右子树
    dfs(l, k - 1);
    dfs(k + 1, r);
}

int main()
{
    // 输入节点数和每个节点的分数，下标从1开始
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }

    /*----- 区间DP：枚举区间长度，由短到长递推 -----*/
    for(int len = 1; len <= n; len++)
    {
        // 枚举区间左端点l
        for(int l = 1; l + len - 1 <= n; l++)
        {
            // 区间右端点r
            int r = l + len - 1;

            // 长度为1（叶节点）：加分就是叶节点本身的分数
            if(l == r)
            {
                f[l][r] = w[l];
                root[l][r] = l;
                continue;
            }

            // 枚举根节点k：区间的每个节点都可能作为根
            for(int k = l; k <= r; k++)
            {
                // 左子树加分：如果k是左端点则左子树为空（规定为1）
                int left = (k == l) ? 1 : f[l][k - 1];
                // 右子树加分：如果k是右端点则右子树为空（规定为1）
                int right = (k == r) ? 1 : f[k + 1][r];

                // 加分计算公式：左子树加分 × 右子树加分 + 根节点分数
                int score = left * right + w[k];

                // 严格使用 < 来更新：保证在得分相同时保留更小的根节点编号
                // 这样最终输出的是字典序最小的前序遍历方案
                if(f[l][r] < score)
                {
                    f[l][r] = score;
                    root[l][r] = k;
                }
            }
        }
    }

    // 输出最高加分
    cout << f[1][n] << endl;
    // 输出前序遍历（字典序最小方案）
    dfs(1, n);

    return 0;
}
