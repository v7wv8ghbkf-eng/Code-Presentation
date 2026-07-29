/*-----题目分析-----
 * 骑士救公主（8方向BFS最短路径）：
 * 在row×col的棋盘上，骑士('K')需要到达公主的位置('H')，'*'是障碍。
 * 骑士每次可以向8个马步方向移动（日字形），求最短步数。
 *
 * 解法：BFS天然保证首次到达目标时的距离即为最短距离
 *-----题目分析-----*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

typedef pair<int, int> PII;

const int N = 155;

int col, row;
char g[N][N];                           // 地图：'K'起点，'H'终点，'*'障碍，'.'空地
int dist[N][N];                         // 距离数组，-1表示未访问
PII start;                              // 骑士起点
PII ending;                             // 公主位置

// 8方向马步（日字形）：(±2,±1) 和 (±1,±2) 的组合
int dx[] = {1, -1, 1, -1, 2, -2, 2, -2};
int dy[] = {2, 2, -2, -2, 1, 1, -1, -1};

/*-----bfs函数分析-----*/
// BFS从起点搜索，找到终点即返回最短距离
// 由于BFS按层扩展，首次遇到终点时的dist即为最短路径长度
int bfs(PII start, PII end)
{
    memset(dist, -1, sizeof(dist));     // 初始化所有距离为-1（未访问）

    queue<PII> q;
    q.push({start.first, start.second});
    dist[start.first][start.second] = 0;

    while (!q.empty())
    {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int x = dx[i] + t.first, y = dy[i] + t.second;

            if (x < 0 || x >= row || y < 0 || y >= col) continue;   // 越界
            if (g[x][y] == '*') continue;                            // 障碍
            if (dist[x][y] != -1) continue;                          // 已访问

            // 到新格子的距离 = 到当前格子距离 + 1
            dist[x][y] = dist[t.first][t.second] + 1;

            // 如果到达终点，直接返回最短距离
            if (make_pair(x, y) == end) return dist[x][y];

            q.push({x, y});
            g[x][y] = '*';              // 标记为已访问（修改地图，无需额外st数组）
        }
    }

    return -1;                          // 无法到达（题目保证有解，此行不会执行）
}

int main()
{
    cin >> col >> row;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'K')         // 骑士起点
            {
                start.first = i;
                start.second = j;
            }
            if (g[i][j] == 'H')         // 公主位置（终点）
            {
                ending.first = i;
                ending.second = j;
            }
        }
    }

    cout << bfs(start, ending) << endl;
    return 0;
}