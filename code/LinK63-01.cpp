#include <iostream>
#include <algorithm>
using namespace std;

// 确认大致的数组范围，防止数组太小、边界太紧从而发生越界
const int N = 1007;

// n件物品，背包容量为m
int n, m;
// 第i件物品的：V体积 / W价值
int V[N], W[N];
/*-----状态表示f[i][j]-----*/
// 【集合】对前i件物品、限定容量为j，所有可能的总价值
int f[N][N];

int main()
{
    // 输入物品数量和背包容量
    cin >> n >> m;

    // 输入每件物品的体积和价值，下标从1开始
    for (int i = 1; i <= n; i++)
    {
        cin >> V[i] >> W[i];
    }

    // 枚举物品件数与限定容量，都是由少到多枚举
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            /*-----集合运算-----*/
            // 对前i件物品与限定容量j而言，f[i][j]有两种可能：
            // 1. 不选第i件物品——等于只考虑前i-1件时的最优解
            // 2. 选第i件物品——因为每件只能用一次，
            //    选了之后只能从"前i-1件物品、容量为j-V[i]"（上一层）转移

            // 这里先认定不选的情况
            f[i][j] = f[i - 1][j];

            // 如果容量j能装下第i件物品，考虑选它
            // 注意：01背包用 f[i-1][j-V[i]]（上一层）
            // 表示选了第i件后，只能从前i-1件继续选，保证每件只用一次
            if (j >= V[i])
                f[i][j] = max(f[i][j], f[i - 1][j - V[i]] + W[i]);
        }
    }

    // 最终所需要的答案：
    // 是同时存在n件物品(每件最多选一次)时，限定(背包)总容量为m，所取得的总价值最大值
    cout << f[n][m] << endl;
    return 0;
}

/*
 * ===== 空间优化版本：一维滚动数组 =====
 * 将f[N][N]压缩为f[N]，逆序枚举容量保证每件物品只选一次。
 * 注意：使用此版本时需将f数组声明改为 int f[N]; 并删除f[i][j]相关代码。
 *
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1007;

int n, m;
int V[N], W[N];
int f[N];  // 一维滚动数组

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> V[i] >> W[i];

    for (int i = 1; i <= n; i++)
    {
        // 逆序枚举：保证f[j-V[i]]是本轮更新前的旧值(等价于f[i-1][j-V[i]])
        for (int j = m; j >= V[i]; j--)
            f[j] = max(f[j], f[j - V[i]] + W[i]);
    }

    cout << f[m] << endl;
    return 0;
}
 * ===== 空间优化版本结束 =====
 */
