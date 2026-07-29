#include<iostream>
#include<algorithm>
using namespace std;

// 确认大致的数组范围，防止数组太小、边界太紧从而发生越界
const int N = 1007;

// n种物品，背包容量为m（数据范围 N,V ≤ 1000）
int n, m;
// 第i种物品的：v体积 / w价值（每种物品有无限件可用）
int v[N], w[N];
/*-----状态表示f[i][j]-----*/
// 【集合】对前i种物品、限定容量为j，所有可能的总价值
int f[N][N];

int main()
{
    // 输入并装填元素，从1开始方便下标观察
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        cin >> v[i] >> w[i];
    }

    // 枚举物品种数与限定容量，都是由少到多枚举
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            /*-----集合运算-----*/
            // 对前i种物品与限定容量j而言，枚举选取第i种物品的数量k：
            // 因为每种物品有无限件，k可以从0取到 j/v[i]（容量上限）
            // f[i][j] = max{ f[i-1][j - k*v[i]] + k*w[i] }   (0 ≤ k ≤ j/v[i])

            // k从0开始枚举：k=0等价于不选第i种物品（f[i-1][j]）
            for(int k = 0; j >= k * v[i]; k++)
            {
                // 选k个第i种物品：腾出k*v[i]容量，获得k*w[i]价值
                // 从 f[i-1][...]（上一层）转移
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }

    // 最终所需要的答案：
    // 是同时存在n种物品(每种无限件)时，限定(背包)总容量为m，所取得的总价值最大值
    cout << f[n][m] << endl;
    return 0;
}

/*
 * ===== 时间优化版本：O(N*V) 二重循环 =====
 * 利用完全背包可重复选取的特性，将枚举k的循环优化掉：
 * f[i][j] = max(f[i-1][j], f[i][j-v[i]] + w[i])
 * 关键区别：用 f[i][j-v[i]]（本层）而非 f[i-1][j-v[i]]（上层），
 * 因为选了第i种之后还能继续选，所以看同层已更新的状态。
 * 同时 j 必须正序枚举（从小到大），保证 f[i][j-v[i]] 已在本层计算完毕。
 *
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1007;

int n, m;
int v[N], w[N];
int f[N][N];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        cin >> v[i] >> w[i];

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
        }
    }

    cout << f[n][m] << endl;
    return 0;
}
 * ===== 时间优化版本结束 =====
 */
