/*-----题目分析-----
 * 迷宫连通区域计数（BFS泛洪填充）：
 * 给定H×W的迷宫，'@'是起点，'.'是可通行区域，'#'是墙壁。
 * 从起点出发，每次可向上下左右移动一格，求能到达的区域总数（含起点）。
 * 多组数据，以"0 0"结束。
 *-----题目分析-----*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 25;
int row, col;                           // 注意：row=H(行数), col=W(列数)
char g[N][N];                           // 地图

int dx[] = {1, -1, 0, 0};              // 四个方向的偏移量
int dy[] = {0, 0, 1, -1};

/*-----bfs函数分析-----*/
// BFS泛洪填充：从起点(x,y)出发，将所有可达的'.'标记为'#'（已访问），统计总格数
// 不需要额外的st数组，直接修改地图即可
int bfs(int x, int y)
{
    queue<PII> q;

    g[x][y] = '#';                      // 标记起点为已访问
    q.push({x, y});
    int res = 0;

    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        res++;                          // 每出队一个格子，计数+1

        for (int i = 0; i < 4; i++)
        {
            int X = t.first + dx[i];
            int Y = t.second + dy[i];

            if (X < 0 || X >= row || Y < 0 || Y >= col)
                continue;               // 越界
            if (g[X][Y] == '#')
                continue;               // 墙壁或已访问

            q.push({X, Y});
            g[X][Y] = '#';              // 入队即标记，避免重复入队
        }
    }

    return res;
}

int main()
{
    // 输入格式：先列数W(col) 后行数H(row)
    while (cin >> col >> row && (col && row))
    {
        int x, y;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> g[i][j];
                if (g[i][j] == '@')     // 记录起点坐标
                {
                    x = i, y = j;
                }
            }
        }

        cout << bfs(x, y) << endl;
    }
    return 0;
}