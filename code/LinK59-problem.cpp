/*-----题目分析-----
 * 维修电路（0-1 BFS/双端队列BFS）：
 * R×C网格，每个格子有'/'或'\'的电子元件（可旋转连接对角线两端）。
 * 求从(0,0)到(R,C)的最少旋转次数，无解输出"NO SOLUTION"。
 *
 * 解法：转化为图论。把格点(R+1)×(C+1)当作节点。
 *   元件'\'连接左上-右下（代价0），旋转后连接右上-左下（代价1）。
 *   用双端队列BFS（0-1 BFS）：边权0的放队首、边权1的放队尾。
 *-----题目分析-----*/
#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

const int N = 510;
int R, C;
char g[N][N];
int dist[N][N];                             // dist[x][y] 到达格点(x,y)的最少旋转次数

int bfs() {
    memset(dist, 0x3f, sizeof(dist));
    deque<pair<int,int>> q;
    q.push_front({0, 0}); dist[0][0] = 0;

    while (!q.empty()) {
        auto f = q.front(); int x = f.first, y = f.second; q.pop_front();
        // 4个方向去往相邻格点（通过某格子的元件）
        // 左上↘：通过格子(x,y)的元件
        if (x > 0 && y > 0) {
            int w = (g[x-1][y-1] == '\\') ? 0 : 1;  // \可直达（0代价），/需旋转（1代价）
            if (dist[x-1][y-1] > dist[x][y] + w) {
                dist[x-1][y-1] = dist[x][y] + w;
                if (w) q.push_back({x-1, y-1}); else q.push_front({x-1, y-1});
            }
        }
        // 右上↙：通过格子(x-1, y)
        if (x > 0 && y < C) {
            int w = (g[x-1][y] == '/') ? 0 : 1;
            if (dist[x-1][y+1] > dist[x][y] + w) {
                dist[x-1][y+1] = dist[x][y] + w;
                if (w) q.push_back({x-1, y+1}); else q.push_front({x-1, y+1});
            }
        }
        // 左下↗：通过格子(x, y-1)
        if (x < R && y > 0) {
            int w = (g[x][y-1] == '/') ? 0 : 1;
            if (dist[x+1][y-1] > dist[x][y] + w) {
                dist[x+1][y-1] = dist[x][y] + w;
                if (w) q.push_back({x+1, y-1}); else q.push_front({x+1, y-1});
            }
        }
        // 右下↖：通过格子(x, y)
        if (x < R && y < C) {
            int w = (g[x][y] == '\\') ? 0 : 1;
            if (dist[x+1][y+1] > dist[x][y] + w) {
                dist[x+1][y+1] = dist[x][y] + w;
                if (w) q.push_back({x+1, y+1}); else q.push_front({x+1, y+1});
            }
        }
    }
    return dist[R][C] == 0x3f3f3f3f ? -1 : dist[R][C];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        cin >> R >> C;
        for (int i = 0; i < R; i++) cin >> g[i];
        // 剪枝：起点和终点的曼哈顿距离必须是偶数（棋盘染色）
        if ((R + C) & 1) { cout << "NO SOLUTION" << endl; continue; }
        int ans = bfs();
        if (ans == -1) cout << "NO SOLUTION" << endl;
        else cout << ans << endl;
    }
    return 0;
}