#include <iostream>
#include <cstring>
using namespace std;

// 剪枝：记忆化
int memo[35][20];

/*-----dfs函数分析-----*/
// dfs：对剩余的m个苹果和n个盘子有几种放法
int dfs(int m, int n)
{
    // 如果没有苹果，只能是全空
    if (m == 0)
        return 1;
    // 如果没有盘子，不存在放法
    if (n == 0)
        return 0;
    // 如果只有一个盘子，存在唯一放法
    if (n == 1)
        return 1;

    if (memo[m][n] != -1) return memo[m][n];

    int res = 0;
    // 如果苹果个数更少，那么只存在放不满的情况
    // 为了确保只考虑“存在空盘子”，直接将必然空的m - n个盘子丢掉
    // 剩下的盘子是继续留有空盘子还是全放满，那是dfs需要考虑的问题
    if (m < n)
        res += dfs(m, m);
    else
    {
        // 将“存在空盘子”与“不存在空盘子的放法”加起来
        res += dfs(m, n - 1) + dfs(m - n, n);
    }
    
    memo[m][n] = res;
    return res;
}

int main()
{
    // 初始化为“未检索” -1
    memset(memo, -1, sizeof(memo));

    int t;
    cin >> t;
    while (t--)
    {
        // M个苹果，放在N个盘子里，允许有盘子空着
        int M, N;
        cin >> M >> N;

        cout << dfs(M, N) << endl;
    }

    return 0;
}