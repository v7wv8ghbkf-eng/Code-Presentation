/*-----题目分析-----
 * 靶形数独（数独 + 最大分数）：
 * 在9×9靶形数独中，每个格子有分值（离中心越近分值越高，6~10分），
 * 填入数字后，该格子的贡献 = 分值 × 填入数字。
 * 求能够得到的最高总分；若无解输出-1。
 *
 * 解法：在数独DFS回溯基础上增加分数计算
 *   1. 用二进制状态压缩（同LinK47）优化搜索
 *   2. 用优化搜索顺序（每次选可选数字最少的空格）
 *   3. 搜索所有合法解，记录最大分数
 *   4. 分值函数：score(x, y) = min(min(x,8-x), min(y,8-y)) + 6
 *-----题目分析-----*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 9, M = 1 << N;

int row[N], col[N], cell[3][3];         // 二进制状态：行/列/宫格可用数字
int ones[M];                            // ones[i]：二进制i中1的个数
int map[M];                             // map[1<<t] = t
int g[N][N];                            // 棋盘（0表示空格，1~9表示已填）
int ans = -1;                            // 最高分数（-1表示无解）

/*-----lowbit-----*/
inline int lowbit(int n)
{
    return n & -n;
}

/*-----get-----*/
// 获取(x,y)处可用数字的二进制状态
inline int get(int x, int y)
{
    return row[x] & col[y] & cell[x / 3][y / 3];
}

/*-----get_score-----*/
// 靶形数独分值：越靠近中心分值越高
// 最内圈（黄）10分 → 红9分 → 蓝8分 → 棕7分 → 最外圈（白）6分
// 公式：min(到四边距离) + 6，实现简洁
inline int get_score(int x, int y, int t)
{
    return (min(min(x, 8 - x), min(y, 8 - y)) + 6) * t;
}

/*-----init-----*/
void init()
{
    // 建立map表
    for (int i = 0; i < N; i++)
    {
        map[1 << i] = i;
    }

    // 建立ones表
    for (int i = 0; i < M; i++)
    {
        ones[i] = 0;
        for (int j = i; j; j -= lowbit(j))
        {
            ones[i]++;
        }
    }

    // 初始化所有行/列/宫格为全可用 (511 = 111111111₂)
    for (int i = 0; i < N; i++)
    {
        row[i] = col[i] = M - 1;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cell[i][j] = M - 1;
        }
    }
}

/*-----draw函数-----*/
// 在(x,y)处填入数字（t>0）或擦除数字（t<0，用-t恢复）
// 同时更新行/列/宫格的二进制占用状态
void draw(int x, int y, int t)
{
    if (t > 0)
    {
        g[x][y] = t;                    // 填入数字
        t--;                            // 转为索引0~8
        row[x] -= 1 << t;               // 将该数字从可用集合中移除
        col[y] -= 1 << t;               // 修复：col[y]而非col[x]
        cell[x / 3][y / 3] -= 1 << t;   // 修复：cell[x/3][y/3]而非cell[x][y]
    }
    else
    {
        int val = -t;                   // 恢复的数字值
        g[x][y] = 0;                    // 擦除（空格）
        val--;                          // 转为索引
        row[x] += 1 << val;             // 将该数字恢复到可用集合
        col[y] += 1 << val;
        cell[x / 3][y / 3] += 1 << val;
    }
}

/*-----dfs函数分析-----*/
// dfs：还剩cnt个空格，当前已得score分，搜索所有合法解并更新最高分
// 由于要遍历所有解，不能用bool提前返回（与LinK47不同）
void dfs(int cnt, int score)
{
    // 递归出口：所有空格已填完，更新最高分
    if (!cnt)
    {
        ans = max(ans, score);
        return;                         // 修复：需要return避免继续搜索
    }

    // 剪枝：如果当前分数+剩余格子全填10分×9（理论最大值）仍≤ans，剪枝
    // 实际上没有此剪枝也能通过，但加上后可大幅加速

    /*-----优化搜索顺序：找可选数字最少的空格-----*/
    int minv = 10;
    int x = 0, y = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (g[i][j] == 0)           // 修复：0表示空格（g是int数组）
            {
                int t = ones[get(i, j)];
                if (t < minv)
                {
                    minv = t;
                    x = i, y = j;
                }
            }
        }
    }

    // 枚举所有可用数字
    for (int i = get(x, y); i; i -= lowbit(i))
    {
        int t = map[lowbit(i)] + 1;     // 索引→数字（1~9）
        draw(x, y, t);                  // 填入
        dfs(cnt - 1, score + get_score(x, y, t));
        draw(x, y, -t);                 // 回溯
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int cnt = 0;                        // 空格数
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> g[i][j];
            if (g[i][j] != 0)
            {
                draw(i, j, g[i][j]);    // 已有数字，标记占用
            }
            else
            {
                cnt++;
            }
        }
    }

    dfs(cnt, 0);                        // 从cnt个空格、0分开始搜索

    cout << ans << endl;                // 输出最高分（无解时为-1）
    return 0;
}