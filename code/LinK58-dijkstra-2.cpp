/*-----棰樼洰鍒嗘瀽-----
 * Dijkstra姹傛渶鐭矾锛堝爢浼樺寲鐗?O(m log n)锛夛細
 * 缁欏畾涓€涓猲涓偣m鏉¤竟鐨勬湁鍚戝浘锛屾墍鏈夎竟鏉冨潎涓烘鍊笺€? * 姹備粠1鍙风偣鍒皀鍙风偣鐨勬渶鐭窛绂伙紝鑻ヤ笉鍙揪鍒欒緭鍑?1銆? *
 * 瑙ｆ硶锛氬爢浼樺寲Dijkstra锛岄€傜敤浜庣█鐤忓浘锛堣竟鏁癿杩滃皬浜巒虏锛? *   鐢ㄤ紭鍏堥槦鍒楋紙灏忔牴鍫嗭級缁存姢(dist, node)锛屾瘡娆″彇鍑哄爢椤剁殑鏈‘瀹氱偣锛? *   鏍囪涓哄凡纭畾锛屽苟鏉惧紱鍏舵墍鏈夊嚭杈广€? * 鏃堕棿澶嶆潅搴?O(m log n)
 *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> PII;                 // (璺濈, 鑺傜偣缂栧彿)

const int N = 150010;                       // 杈规暟涓婇檺
const int INF = 0x3f3f3f3f;

int n, m;

/*-----閭绘帴琛?----*/
// h[i]锛氫互i涓鸿捣鐐圭殑绗竴鏉¤竟鐨勭储寮?// e[idx]锛氱idx鏉¤竟鐨勭粓鐐癸紱w[idx]锛氳竟鏉冿紱ne[idx]锛氫笅涓€鏉¤竟鐨勭储寮?int h[N], e[N], ne[N], w[N], idx;

int dist[N];                                // dist[i]锛?鍒癷鐨勬渶鐭窛绂?bool st[N];                                 // st[i]锛歩鐨勬渶鐭窛绂绘槸鍚﹀凡纭畾

/*-----add锛氭坊鍔犱竴鏉℃湁鍚戣竟 a鈫抌锛屾潈鍊间负c-----*/
void add(int a, int b, int c) {
    e[idx] = b;                             // 杈圭殑缁堢偣
    w[idx] = c;                             // 杈规潈
    ne[idx] = h[a];                         // 閾捐〃澶存彃娉曪細鏂拌竟鎸囧悜鍘熼摼琛ㄥご
    h[a] = idx++;                           // 鏇存柊閾捐〃澶?}

/*-----dijkstra鍑芥暟鍒嗘瀽-----*/
// 鍫嗕紭鍖朌ijkstra锛氱敤浼樺厛闃熷垪鑷姩缁存姢褰撳墠dist鏈€灏忕殑鑺傜偣
int dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    memset(st, false, sizeof(st));
    dist[1] = 0;

    // 灏忔牴鍫嗭細鎸夎窛绂讳粠灏忓埌澶ф帓鍒?    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});                      // (璺濈, 鑺傜偣缂栧彿)

    while (!heap.empty()) {
        auto top = heap.top(); int d = top.first, t = top.second; // d鏄?鍒皌鐨勫綋鍓嶆渶鐭窛绂?        heap.pop();

        if (st[t]) continue;                // 宸茬‘瀹氾紝璺宠繃锛堝爢涓彲鑳芥湁杩囨湡鏁版嵁锛?        st[t] = true;                       // 鏍囪t鐨勬渶鐭窛绂诲凡纭畾

        /*-----鏉惧紱t鐨勬墍鏈夊嚭杈?----*/
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];                   // 閭绘帴鐐?            // 濡傛灉閫氳繃t鍒拌揪j姣斿綋鍓峝ist[j]鏇寸煭锛屽垯鏇存柊骞跺叆鍫?            if (dist[j] > d + w[i]) {
                dist[j] = d + w[i];
                heap.push({dist[j], j});    // 娉ㄦ剰锛氬彲鑳芥湁閲嶅鑺傜偣锛岀敱st[t]妫€鏌ュ幓閲?            }
        }
    }

    if (dist[n] == INF) return -1;          // 涓嶅彲杈?    return dist[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h, -1, sizeof(h));               // 閭绘帴琛ㄥご鍒濆鍖栦负-1锛堢┖閾捐〃锛?    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);                       // 閭绘帴琛ㄨ嚜鍔ㄥ鐞嗛噸杈癸紙澶氭潯杈瑰叡瀛橈級
    }

    cout << dijkstra() << endl;
    return 0;
}