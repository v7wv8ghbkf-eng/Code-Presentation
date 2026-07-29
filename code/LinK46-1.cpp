/*-----题目分析-----
 * 数独求解（DFS回溯）：给定一个9×9的数独初始状态（0表示空格），
 * 填入1~9使每行、每列、每个3×3宫格内数字1~9恰好出现一次。
 * 只需输出任意一种合法解。
 *
 * 解法：DFS逐格回溯
 *   用 row[x][t]、col[y][t]、cell[x/3][y/3][t] 三个bool数组标记
 *   第x行/第y列/第(x/3,y/3)宫格中数字t是否已被占用，
 *   每次选择可选数字尝试填入，失败则回溯。
 *-----题目分析-----*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 9;

int g[N][N];                            // 数独棋盘（0表示空格）

/*-----占用标记数组-----*/
// row[x][t]: 第x行中数字t是否已被使用（t范围1~9，下标0浪费不用）
// col[y][t]: 第y列中数字t是否已被使用
// cell[i][j][t]: 第(i,j)个3×3宫格（i,j ∈ {0,1,2}）中数字t是否已被使用
bool row[N][N + 1], col[N][N + 1], cell[3][3][N + 1];

/*-----dfs函数分析-----*/
// dfs：从坐标(x, y)开始搜索，尝试填入1~9中未被占用的数字
// 搜索顺序：从左到右逐格扫描，到达行末(y==9)则换行，到达棋盘末尾(x==9)则输出解
// 返回值：bool类型，找到解返回true使上层递归提前终止（只需输出一个解）
bool dfs(int x, int y)
{
    // 行末换行：当前行扫描完，跳到下一行开头
    if (y == 9)
    {
        x++, y = 0;
    }
    // 递归出口：所有行都处理完，输出解
    if (x == 9)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf("%d", g[i][j]);
            }
            printf("\n");
        }
        return true;                    // 找到解，返回true
    }

    // 如果当前格子已有数字（非0），跳过，继续下一格
    if (g[x][y] != 0)
    {
        return dfs(x, y + 1);           // 递归结果直接返回，使找到解后能逐层终止
    }

    /*-----尝试填入数字-----*/
    // 枚举1~9，检查行、列、宫格是否允许
    for (int t = 1; t < 10; t++)
    {
        if (!row[x][t] && !col[y][t] && !cell[x / 3][y / 3][t])
        {
            // 放置数字t
            g[x][y] = t;
            row[x][t] = col[y][t] = cell[x / 3][y / 3][t] = true;

            // 递归下一格，如果一路到底找到解，逐层返回true终止搜索
            if (dfs(x, y + 1))
                return true;

            // 回溯：撤销本次放置
            row[x][t] = col[y][t] = cell[x / 3][y / 3][t] = false;
            g[x][y] = 0;
        }
    }

    return false;                       // 所有数字都不可行，回溯
}

int main()
{
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    memset(cell, false, sizeof(cell));

    // 读入初始棋盘状态，同时更新占用标记
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            char ch;
            scanf(" %c", &ch);          // " %c"前加空格跳过空白字符（换行等）
            int x = ch - '0';
            g[i][j] = x;
            if (x != 0)                 // 已有数字则标记行、列、宫格占用
            {
                row[i][x] = col[j][x] = cell[i / 3][j / 3][x] = true;
            }
        }
    }

    dfs(0, 0);                          // 从(0,0)开始搜索
    return 0;
}