#include <iostream>
using namespace std;

// 确认大致的数组范围，防止数组太小、边界太紧从而发生越界
// 注意：朴素方法只需 N≤110（si≤100 时三重循环可过）；
//       二进制优化版本需要 N≥12000（拆分后物品数上限）
const int N = 110;
// 背包容量上限（朴素方法 V≤100）
const int M = 110;

// num种物品，背包容量为V（本题朴素版数据范围：N,V,si ≤ 100）
int num, V;
// 第i种物品的：v体积 / w价值 / s数量(最多s件)
int v[N], w[N], s[N];
/*-----状态表示f[i][j]-----*/
// 【集合】对前i种物品、限定容量为j，所有可能的总价值
int f[N][M];

int main()
{
    // 输入并装填元素，从1开始方便下标观察
    cin >> num >> V;
    for (int i = 1; i <= num; i++)
    {
        cin >> v[i] >> w[i] >> s[i];
    }

    // 枚举物品种数与限定容量，都是由少到多枚举
    for (int i = 1; i <= num; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            /*-----集合运算-----*/
            // 对前i种物品与限定容量j而言，枚举选取第i种物品的数量k：
            // k从0取到 min(s[i], j/v[i])，逐一比较取最大值
            // f[i][j] = max{ f[i-1][j - k*v[i]] + k*w[i] }  (0 ≤ k ≤ s[i], k*v[i] ≤ j)

            // k从0开始枚举：k=0等价于不选第i种物品（f[i-1][j]）
            for (int k = 0; k <= s[i] && j >= k * v[i]; k++)
            {
                // 选k个第i种物品：腾出k*v[i]容量，获得k*w[i]价值
                // 从 f[i-1][...]（上一层）转移，保证不超出数量限制
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }

    // 最终所需要的答案：
    // 是同时存在num种物品(每种有数量限制)时，限定(背包)总容量为V，所取得的总价值最大值
    cout << f[num][V] << endl;
    return 0;
}

/*
 * ===== 二进制优化版本：适用于大数据范围 (N,V,si ≤ 1000~2000) =====
 * 核心思想：将每种物品的si件按1,2,4,8,...打包成若干"大物品"，
 * 任意数量k(0≤k≤si)都可以通过这些包的组合精确表示。
 * 然后将打包后的物品做一遍01背包即可。
 * 复杂度：O( N*log(max_si) * V )，远优于朴素O(N*V*max_si)。
 *
#include <iostream>
using namespace std;

const int N = 12000;  // 二进制拆分后物品数上限 (1000 * log2(2000) ≈ 11000)
const int M = 2010;   // 背包容量上限

int num, V;
int f[M];             // 一维滚动数组
int v[N], w[N];       // 拆分后第cnt个打包物品的体积/价值

int main()
{
    cin >> num >> V;

    int cnt = 0;  // 拆分后的打包物品总数
    for (int i = 1; i <= num; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;

        // 二进制拆分：每次取1,2,4,8,...件打包
        int k = 1;
        while (k <= s)
        {
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        // 剩余不足一包的部分
        if (s > 0)
        {
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    num = cnt;

    // 01背包：对拆分后的打包物品做一维DP
    for (int i = 1; i <= num; i++)
        for (int j = V; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[V] << endl;
    return 0;
}
 * ===== 二进制优化版本结束 =====
 */
