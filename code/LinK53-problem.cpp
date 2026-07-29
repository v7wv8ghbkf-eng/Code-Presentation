/*-----题目分析-----
 * 马走日（8方向BFS最远距离）：
 * 在row×col的棋盘上，从起点出发，每次可向8个马步方向移动（日字形），
 * 不可走出棋盘或经过障碍('*')。求从起点到任意可达格子的最远距离（步数）。
 *
 * 输入：col row start_x start_y，然后是棋盘（'.'空地，'*'障碍）
 * 注意：输入顺序是先col(列)后row(行)，且坐标从1开始
 *-----题目分析-----*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 110;
int row, col;
PII start;                              // 起点坐标
char g[N][N];                           // 地图（1-indexed）
int dist[N][N];                         // dist[x][y]：起点到(x,y)的最短距离

// 8方向马步：日字形移动（先直走再斜走）
const int dx[] = {1, -1, 1, -1, 0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

/*-----bfs函数分析-----*/
// BFS求从起点出发到所有可达格子的最远距离
// 由于BFS天然按距离分层，每层距离+1，最终遍历到的最大dist即为最远距离
int bfs()
{
    memset(dist, -1, sizeof(dist));     // -1表示未访问

    queue<PII> q;
    q.push(start);
    dist[start.first][start.second] = 0;

    int res = 0;                        // 记录最远距离
    while (q.size())
    {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];

            // 棋盘坐标从1开始到row/col
            if (x < 1 || x > row || y < 1 || y > col) continue;
            if (g[x][y] == '*' || dist[x][y] != -1) continue;  // 障碍或已访问

            // 新格子的距离 = 前一格距离 + 1
            dist[x][y] = dist[t.first][t.second] + 1;
            res = max(res, dist[x][y]); // 更新最远距离
            q.push(make_pair(x, y));
        }
    }

    return res;                         // 注意：若没有可达格子（除起点），返回0
}

int main()
{
    // 输入顺序：列col 行row 起点_x 起点_y
    cin >> col >> row >> start.first >> start.second;

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cin >> g[i][j];
        }
    }

    cout << bfs() << endl;
    return 0;
}