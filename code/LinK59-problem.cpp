/*-----棰樼洰鍒嗘瀽-----
 * 缁翠慨鐢佃矾锛?-1 BFS/鍙岀闃熷垪BFS锛夛細
 * R脳C缃戞牸锛屾瘡涓牸瀛愭湁'/'鎴?\'鐨勭數瀛愬厓浠讹紙鍙棆杞繛鎺ュ瑙掔嚎涓ょ锛夈€? * 姹備粠(0,0)鍒?R,C)鐨勬渶灏戞棆杞鏁帮紝鏃犺В杈撳嚭"NO SOLUTION"銆? *
 * 瑙ｆ硶锛氳浆鍖栦负鍥捐銆傛妸鏍肩偣(R+1)脳(C+1)褰撲綔鑺傜偣銆? *   鍏冧欢'\'杩炴帴宸︿笂-鍙充笅锛堜唬浠?锛夛紝鏃嬭浆鍚庤繛鎺ュ彸涓?宸︿笅锛堜唬浠?锛夈€? *   鐢ㄥ弻绔槦鍒桞FS锛?-1 BFS锛夛細杈规潈0鐨勬斁闃熼銆佽竟鏉?鐨勬斁闃熷熬銆? *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

const int N = 510;
int R, C;
char g[N][N];
int dist[N][N];                             // dist[x][y] 鍒拌揪鏍肩偣(x,y)鐨勬渶灏戞棆杞鏁?
int bfs() {
    memset(dist, 0x3f, sizeof(dist));
    deque<pair<int,int>> q;
    q.push_front({0, 0}); dist[0][0] = 0;

    while (!q.empty()) {
        auto f = q.front(); int x = f.first, y = f.second; q.pop_front();
        // 4涓柟鍚戝幓寰€鐩搁偦鏍肩偣锛堥€氳繃鏌愭牸瀛愮殑鍏冧欢锛?        // 宸︿笂鈫橈細閫氳繃鏍煎瓙(x,y)鐨勫厓浠?        if (x > 0 && y > 0) {
            int w = (g[x-1][y-1] == '\\') ? 0 : 1;  // \鍙洿杈撅紙0浠ｄ环锛夛紝/闇€鏃嬭浆锛?浠ｄ环锛?            if (dist[x-1][y-1] > dist[x][y] + w) {
                dist[x-1][y-1] = dist[x][y] + w;
                if (w) q.push_back({x-1, y-1}); else q.push_front({x-1, y-1});
            }
        }
        // 鍙充笂鈫欙細閫氳繃鏍煎瓙(x-1, y)
        if (x > 0 && y < C) {
            int w = (g[x-1][y] == '/') ? 0 : 1;
            if (dist[x-1][y+1] > dist[x][y] + w) {
                dist[x-1][y+1] = dist[x][y] + w;
                if (w) q.push_back({x-1, y+1}); else q.push_front({x-1, y+1});
            }
        }
        // 宸︿笅鈫楋細閫氳繃鏍煎瓙(x, y-1)
        if (x < R && y > 0) {
            int w = (g[x][y-1] == '/') ? 0 : 1;
            if (dist[x+1][y-1] > dist[x][y] + w) {
                dist[x+1][y-1] = dist[x][y] + w;
                if (w) q.push_back({x+1, y-1}); else q.push_front({x+1, y-1});
            }
        }
        // 鍙充笅鈫栵細閫氳繃鏍煎瓙(x, y)
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
        // 鍓灊锛氳捣鐐瑰拰缁堢偣鐨勬浖鍝堥】璺濈蹇呴』鏄伓鏁帮紙妫嬬洏鏌撹壊锛?        if ((R + C) & 1) { cout << "NO SOLUTION" << endl; continue; }
        int ans = bfs();
        if (ans == -1) cout << "NO SOLUTION" << endl;
        else cout << ans << endl;
    }
    return 0;
}