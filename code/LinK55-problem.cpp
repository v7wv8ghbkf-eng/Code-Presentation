/*-----题目分析-----
 * 多源BFS：给定N×M的01矩阵，计算每个位置到最近'1'的曼哈顿距离。
 * 等价于：所有'1'同时作为起点向外扩展，BFS逐层扩散。
 *
 * 解法：将所有'1'入队（距离=0），BFS向外扩展4个方向，
 *       每个格子的距离 = 前一格距离 + 1。
 * 时间复杂度 O(N×M)
 *-----题目分析-----*/
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

const int MAXN = 1005;
const int INF = 1e9;
int dist[MAXN][MAXN];                       // dist[i][j]：(i,j)到最近'1'的距离
int n, m;

int dx[] = {0, 0, 1, -1};                  // 4方向偏移
int dy[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    /*-----多源BFS-----*/
    // 初始状态：所有'1'位置距离为0，同时入队
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1') {
                dist[i][j] = 0;             // 源头距离为0
                q.push({i, j});
            } else {
                dist[i][j] = INF;           // 未访问标记为INF
            }
        }
    }

    // BFS逐层扩散
    while (!q.empty()) {
        auto t = q.front(); int x = t.first, y = t.second;
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            // 只访问未到达过的格子（dist==INF），BFS保证首次到达即最短距离
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // 输出结果矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j];
            if (j < m - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}