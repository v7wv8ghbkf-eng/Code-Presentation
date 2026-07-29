#include <iostream>
#include <algorithm>
using namespace std;

// 确认大致的数组范围，防止数组太小、边界太紧从而发生越界
const int N = 110;

// 花生地的行数和列数
int row, col;
// w[i][j]第i行第j列的花生数量；f[i][j]从左上角到达(i,j)能摘到的最大花生数
int w[N][N], f[N][N];

int main()
{
    // T组测试数据
    int T;
    cin >> T;
    while (T--)
    {
        // 输入花生地的行数和列数
        cin >> row >> col;

        // 输入每株花生苗上的花生数量，下标从1开始
        for (int i = 1; i <= row; i++)
            for (int j = 1; j <= col; j++)
                cin >> w[i][j];

        /*----- 状态递推：逐行逐列计算 -----*/
        // 只能向东(右)或向南(下)走，所以：
        // 到达(i,j)只能从上边(i-1,j)或左边(i,j-1)来
        // f[i][j] = max(上边来的值, 左边来的值) + 当前位置花生数
        for(int x = 1; x <= row; x++)
        {
            for(int y = 1; y <= col; y++)
            {
                // f[x-1][y]和f[x][y-1]在边界外自动为0（全局数组已初始化）
                f[x][y] = max(f[x - 1][y], f[x][y - 1]) + w[x][y];
            }
        }

        // 最终答案：走到右下角(row,col)时摘到的最大花生总数
        cout << f[row][col] << endl;
    }
    return 0;
}
