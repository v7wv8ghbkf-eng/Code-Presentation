/*-----题目分析-----
 * 递归实现组合型枚举：从1~n这n个整数中随机选出m个，输出所有可能的选择方案。
 * 输入：n, m（0≤m≤n, n+(n-m)≤25）
 * 输出：按字典序输出所有方案，每行m个数升序排列
 * 思路：DFS枚举组合，从start开始依次选数，用depth控制递归层数（即已选数量）
 *       剪枝：当剩余可选数字不足以凑满m个时提前返回
 *-----题目分析-----*/
#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<int> path;       // 当前组合路径

/*-----dfs函数分析-----*/
// dfs：从start开始选数，当前已选depth个，最终需要选满m个
// 递归出口：depth == m 时输出当前组合
// 剪枝策略：当剩余可选数字 (n - start + 1) 不足凑满还需的 (m - depth) 个时，提前返回
void dfs(int start, int depth)
{
    // 递归出口：已选满m个数，输出当前组合
    if (depth == m)
    {
        for (int i = 0; i < (int)path.size(); i++)
        {
            cout << path[i];
            if (i != (int)path.size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
        return;
    }

    /*-----剪枝-----*/
    // 如果起始位置已越界，或者剩余可选数字不足，直接返回
    // 剩余可选数字 = n - start + 1，还需选 = m - depth
    if (start > n || depth + n - start + 1 < m)
    {
        return;
    }

    // 横向枚举：从start开始依次尝试选择每个数加入组合
    // i从start开始保证了组合内元素升序，避免重复
    for (int i = start; i <= n; i++)
    {
        path.push_back(i);
        dfs(i + 1, depth + 1);      // 竖向深入：下一个数从i+1开始选
        path.pop_back();            // 回溯：撤销选择
    }
}

int main()
{
    cin >> n >> m;
    dfs(1, 0);      // 从1开始选，初始已选0个
    return 0;
}