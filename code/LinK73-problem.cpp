#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

// 确认大致的数组范围，防止数组太小、边界太紧从而发生越界
const int N = 1010;

// n个导弹（由输入动态确定数量）
int n;
// h[i]第i个导弹的高度；f[i]以第i个导弹结尾的最长不升子序列长度
int h[N], f[N];
// q数组用于贪心求最少系统数：q[k]存储第k套系统当前能拦截的最低高度
int q[N];

int main()
{
    // 输入：一行以空格分隔的导弹高度
    // 使用getline+stringstream处理不确定数量的输入
    string line;
    getline(cin, line);
    stringstream ssin(line);
    while (ssin >> h[n])
        n++;

    /*----- 同时求解两问 -----*/
    // res: 第一问答案 —— 最多能拦截的导弹数（最长不升子序列长度）
    // cnt: 第二问答案 —— 最少需要的系统数（贪心序列覆盖）
    int res = 0, cnt = 0;

    for (int i = 0; i < n; i++)
    {
        /*----- 第一问：最长不升子序列 O(N²) -----*/
        // 【集合f[i]】以第i个导弹结尾的最长不升子序列长度
        // “不升”的含义：每一发都不能高于前一发，即 h[i] <= h[j]（j是i之前的位置）
        f[i] = 1; // 最少可以只拦截自身
        for (int j = 0; j < i; j++)
        {
            // 如果前面的导弹高度 >= 当前导弹高度，则可以接上
            if (h[i] <= h[j])
                f[i] = max(f[i], f[j] + 1);
        }
        // 更新全局最长不升子序列长度
        res = max(res, f[i]);

        /*----- 第二问：最少系统数（贪心）-----*/
        // 维护q数组，q[k]表示第k套系统当前能拦截的最低高度（最高的那个已拦截导弹）
        // 对于每个新导弹h[i]，在已有系统中找第一个q[k] >= h[i]的（即最低的那个能拦截它的）
        // 如果找不到，说明需要新增一套系统
        int k = 0;
        while (k < cnt && q[k] < h[i])
            k++;

        if (k == cnt)
            // 所有现有系统都不能拦截当前导弹，新增一套
            q[cnt++] = h[i];
        else
            // 第k套系统可以拦截，更新其拦截高度
            q[k] = h[i];
    }

    // 第一行：最多能拦截的导弹数
    cout << res << endl
    // 第二行：要拦截所有导弹最少要配备的系统数
         << cnt << endl;
    return 0;
}
