/*-----棰樼洰鍒嗘瀽-----
 * 澶氭簮BFS锛氱粰瀹歂脳M鐨?1鐭╅樀锛岃绠楁瘡涓綅缃埌鏈€杩?1'鐨勬浖鍝堥】璺濈銆? * 绛変环浜庯細鎵€鏈?1'鍚屾椂浣滀负璧风偣鍚戝鎵╁睍锛孊FS閫愬眰鎵╂暎銆? *
 * 瑙ｆ硶锛氬皢鎵€鏈?1'鍏ラ槦锛堣窛绂?0锛夛紝BFS鍚戝鎵╁睍4涓柟鍚戯紝
 *       姣忎釜鏍煎瓙鐨勮窛绂?= 鍓嶄竴鏍艰窛绂?+ 1銆? * 鏃堕棿澶嶆潅搴?O(N脳M)
 *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

const int MAXN = 1005;
const int INF = 1e9;
int dist[MAXN][MAXN];                       // dist[i][j]锛?i,j)鍒版渶杩?1'鐨勮窛绂?int n, m;

int dx[] = {0, 0, 1, -1};                  // 4鏂瑰悜鍋忕Щ
int dy[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    /*-----澶氭簮BFS-----*/
    // 鍒濆鐘舵€侊細鎵€鏈?1'浣嶇疆璺濈涓?锛屽悓鏃跺叆闃?    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1') {
                dist[i][j] = 0;             // 婧愬ご璺濈涓?
                q.push({i, j});
            } else {
                dist[i][j] = INF;           // 鏈闂爣璁颁负INF
            }
        }
    }

    // BFS閫愬眰鎵╂暎
    while (!q.empty()) {
        auto t = q.front(); int x = t.first, y = t.second;
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            // 鍙闂湭鍒拌揪杩囩殑鏍煎瓙锛坉ist==INF锛夛紝BFS淇濊瘉棣栨鍒拌揪鍗虫渶鐭窛绂?            if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // 杈撳嚭缁撴灉鐭╅樀
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j];
            if (j < m - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}