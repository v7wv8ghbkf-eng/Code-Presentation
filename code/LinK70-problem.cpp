#include <iostream>
#include <algorithm>
using namespace std;

// 确认大致的数组范围，防止数组太小、边界太紧从而发生越界
const int N = 110;
// 定义无穷大常量，用于初始化最小费用的比较
const int INF = 1e9;

// 正方形的宽度N
int s;
// w[i][j]第i行第j列方格的费用；f[i][j]从左上角到达(i,j)的最小总费用
int w[N][N], f[N][N];

int main()
{
    // 输入正方形的宽度
    cin >> s;

    // 输入每个方格的费用，下标从1开始
    for (int i = 1; i <= s; i++)
        for (int j = 1; j <= s; j++)
            cin >> w[i][j];

    /*----- 状态递推：逐行逐列计算最小费用 -----*/
    // 题目要求必须在(2N-1)单位时间内穿越，这意味着只能向右或向下走
    // （如果往回走会超时），所以与"摘花生"思路类似，但求的是最小值
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            // 起点特殊处理：没有"从哪边来"的选择
            if (i == 1 && j == 1)
                f[i][j] = w[i][j];
            else
            {
                // 先初始化为无穷大，再用min选出较小路径
                f[i][j] = INF;
                // 如果上方有格子，考虑从上边来
                if (i > 1)
                    f[i][j] = min(f[i][j], f[i - 1][j] + w[i][j]);
                // 如果左方有格子，考虑从左边来
                if (j > 1)
                    f[i][j] = min(f[i][j], f[i][j - 1] + w[i][j]);
            }
        }
    }

    // 最终答案：从左上角(1,1)到右下角(s,s)的最小总费用
    cout << f[s][s] << endl;
    return 0;
}
