/*-----题目分析-----
 * 最省赛程（状态图Dijkstra）：
 * N个城市M条赛道（无向图），每城市有油价P_i。车油箱容量C，初始空油。
 * q个查询(S,E,C)，求从S到E的最少油钱，不可达输出"impossible"。
 *
 * 解法：Dijkstra在状态图(city, fuel)上求最短路。
 *   状态转移有两种：
 *     1. 在当前城市加1单位油：cost+P[city], fuel+1 (if fuel<C)
 *     2. 去相邻城市：fuel-d (if fuel>=d)
 *   状态数N×C最多约1000×100=100000，用优先队列优化。
 *-----题目分析-----*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

const int N = 1010, M = 20010, C_MAX = 110;

int n, m;
int price[N];                               // 各城市油价
int h[N], e[M], ne[M], w[M], idx;           // 邻接表（无向边）

void add(int a, int b, int c) {
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

/*-----状态图Dijkstra-----*/
// dist[city][fuel]：到达某城市、油量为fuel时的最小花费
int dist[N][C_MAX];
bool vis[N][C_MAX];                         // 访问标记（可复用）

struct State {
    int cost, city, fuel;
    bool operator<(const State &o) const { return cost > o.cost; }  // 小根堆
};

int dijkstra(int C, int S, int E) {
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    priority_queue<State> pq;

    dist[S][0] = 0;
    pq.push({0, S, 0});

    while (!pq.empty()) {
        auto top = pq.top(); pq.pop(); int cur_cost = top.cost, u = top.city, f = top.fuel;
        if (u == E) return cur_cost;        // 到达终点，首次即最优
        if (vis[u][f]) continue;
        vis[u][f] = true;

        /*-----转移1：在当前城市加1单位油-----*/
        if (f < C) {
            int nxt_cost = cur_cost + price[u];
            int nxt_f = f + 1;
            if (dist[u][nxt_f] > nxt_cost) {
                dist[u][nxt_f] = nxt_cost;
                pq.push({nxt_cost, u, nxt_f});
            }
        }

        /*-----转移2：去相邻城市-----*/
        for (int i = h[u]; i != -1; i = ne[i]) {
            int v = e[i], d = w[i];
            if (f >= d) {
                int nxt_f = f - d;
                if (dist[v][nxt_f] > cur_cost) {
                    dist[v][nxt_f] = cur_cost;
                    pq.push({cur_cost, v, nxt_f});
                }
            }
        }
    }
    return -1;                              // 不可达
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    memset(h, -1, sizeof(h));

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> price[i];
    while (m--) {
        int u, v, d; cin >> u >> v >> d;
        add(u, v, d); add(v, u, d);         // 无向边
    }

    int q; cin >> q;
    while (q--) {
        int C, S, E; cin >> C >> S >> E;
        int ans = dijkstra(C, S, E);
        if (ans == -1) cout << "impossible" << endl;
        else           cout << ans << endl;
    }
    return 0;
}