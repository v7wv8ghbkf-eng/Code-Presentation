/*-----棰樼洰鍒嗘瀽-----
 * 鏈€鐪佽禌绋嬶紙鐘舵€佸浘Dijkstra锛夛細
 * N涓煄甯侻鏉¤禌閬擄紙鏃犲悜鍥撅級锛屾瘡鍩庡競鏈夋补浠稰_i銆傝溅娌圭瀹归噺C锛屽垵濮嬬┖娌广€? * q涓煡璇?S,E,C)锛屾眰浠嶴鍒癊鐨勬渶灏戞补閽憋紝涓嶅彲杈捐緭鍑?impossible"銆? *
 * 瑙ｆ硶锛欴ijkstra鍦ㄧ姸鎬佸浘(city, fuel)涓婃眰鏈€鐭矾銆? *   鐘舵€佽浆绉绘湁涓ょ锛? *     1. 鍦ㄥ綋鍓嶅煄甯傚姞1鍗曚綅娌癸細cost+P[city], fuel+1 (if fuel<C)
 *     2. 鍘荤浉閭诲煄甯傦細fuel-d (if fuel>=d)
 *   鐘舵€佹暟N脳C鏈€澶氱害1000脳100=100000锛岀敤浼樺厛闃熷垪浼樺寲銆? *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

const int N = 1010, M = 20010, C_MAX = 110;

int n, m;
int price[N];                               // 鍚勫煄甯傛补浠?int h[N], e[M], ne[M], w[M], idx;           // 閭绘帴琛紙鏃犲悜杈癸級

void add(int a, int b, int c) {
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

/*-----鐘舵€佸浘Dijkstra-----*/
// dist[city][fuel]锛氬埌杈炬煇鍩庡競銆佹补閲忎负fuel鏃剁殑鏈€灏忚姳璐?int dist[N][C_MAX];
bool vis[N][C_MAX];                         // 璁块棶鏍囪锛堝彲澶嶇敤锛?
struct State {
    int cost, city, fuel;
    bool operator<(const State &o) const { return cost > o.cost; }  // 灏忔牴鍫?};

int dijkstra(int C, int S, int E) {
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    priority_queue<State> pq;

    dist[S][0] = 0;
    pq.push({0, S, 0});

    while (!pq.empty()) {
        auto top = pq.top(); pq.pop(); int cur_cost = top.cost, u = top.city, f = top.fuel;
        if (u == E) return cur_cost;        // 鍒拌揪缁堢偣锛岄娆″嵆鏈€浼?        if (vis[u][f]) continue;
        vis[u][f] = true;

        /*-----杞Щ1锛氬湪褰撳墠鍩庡競鍔?鍗曚綅娌?----*/
        if (f < C) {
            int nxt_cost = cur_cost + price[u];
            int nxt_f = f + 1;
            if (dist[u][nxt_f] > nxt_cost) {
                dist[u][nxt_f] = nxt_cost;
                pq.push({nxt_cost, u, nxt_f});
            }
        }

        /*-----杞Щ2锛氬幓鐩搁偦鍩庡競-----*/
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
    return -1;                              // 涓嶅彲杈?}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    memset(h, -1, sizeof(h));

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> price[i];
    while (m--) {
        int u, v, d; cin >> u >> v >> d;
        add(u, v, d); add(v, u, d);         // 鏃犲悜杈?    }

    int q; cin >> q;
    while (q--) {
        int C, S, E; cin >> C >> S >> E;
        int ans = dijkstra(C, S, E);
        if (ans == -1) cout << "impossible" << endl;
        else           cout << ans << endl;
    }
    return 0;
}