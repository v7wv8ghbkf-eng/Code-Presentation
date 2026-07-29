/*-----棰樼洰鍒嗘瀽-----
 * 鎷撴墤鎺掑簭锛歯涓偣m鏉¤竟鏈夊悜鍥撅紝杈撳嚭浠讳竴鎷撴墤搴忓垪锛涜嫢鏃狅紙瀛樺湪鐜級杈撳嚭-1銆? *
 * 瑙ｆ硶锛欱FS Kahn绠楁硶銆傜粺璁℃瘡涓偣鐨勫叆搴ndeg锛? *   灏嗗叆搴︿负0鐨勭偣鍏ラ槦锛岄€愪竴鍙栧嚭骞跺垹闄ゅ叾鍑鸿竟锛堥偦鎺ョ偣鍏ュ害-1锛夛紝
 *   鏂板叆搴﹀彉涓?鐨勭偣鍏ラ槦銆傝嫢鏈€缁堣緭鍑虹偣鏁?n鍒欏瓨鍦ㄧ幆銆? *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;                 // 閭绘帴琛?int indeg[N];                               // indeg[i]锛氱偣i鐨勫叆搴?vector<int> topo;                           // 鎷撴墤搴忓垪

void add(int a, int b) {
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

bool kahn() {
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0) q.push(i);       // 鍏ュ害涓?鐨勭偣鍏ラ槦

    while (!q.empty()) {
        int t = q.front(); q.pop();
        topo.push_back(t);
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (--indeg[j] == 0) q.push(j); // 鍒犺竟鍚庡叆搴﹀彉0鍒欏叆闃?        }
    }
    return (int)topo.size() == n;           // 鏄惁鎵€鏈夌偣閮藉叆浜嗘嫇鎵戝簭
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        add(a, b); indeg[b]++;
    }
    if (kahn()) {
        for (int i = 0; i < n; i++)
            cout << topo[i] << (i == n-1 ? "\n" : " ");
    } else {
        cout << -1 << endl;
    }
    return 0;
}