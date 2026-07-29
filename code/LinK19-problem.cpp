/*-----题目分析-----
 * 递归实现指数型枚举：从1~n这n个整数中随机选取任意多个（0~n个），输出所有可能的选择方案。
 * 输入：n（1<=n<=15）
 * 输出：每行一种方案，行内升序排列；空方案输出空行；各行顺序任意（有SPJ校验）
 * 思路：DFS枚举每个数的选/不选，等价于枚举{1,2,...,n}的所有子集
 *-----题目分析-----*/
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> path;       // 当前子集路径

/*-----dfs函数分析-----*/
// dfs：枚举从start开始的所有子集，当前路径path中保存已选的数
// 递归策略：每个节点先输出当前路径（即一个子集），再枚举下一个选的数
// 关键设计：每次进入dfs先输出，保证空集也能输出；然后从start往后选数，
//          保证子集内元素升序，同时避免重复（如{1,2}和{2,1}只输出一次）
void dfs(int start) {
    // 将当前路径中的子集输出（每个节点都是一个合法子集，包括空集）
    for (int i = 0; i < (int)path.size(); i++)
    {
        if (i > 0) cout << " ";
        cout << path[i];
    }
    cout << endl;

    // 横向枚举：从start开始依次尝试选择每个数加入子集
    // i从start开始保证了升序，避免重复子集
    for (int i = start; i <= n; i++)
    {
        path.push_back(i);      // 选择i加入当前子集
        dfs(i + 1);             // 竖向深入：下一个数从i+1开始选（保证升序）
        path.pop_back();        // 回溯：撤销选择，横向尝试下一个数
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}