/*-----棰樼洰鍒嗘瀽-----
 * Dijkstra姹傛渶鐭矾锛堟湸绱犵増 O(n虏)锛夛細
 * 缁欏畾涓€涓猲涓偣m鏉¤竟鐨勬湁鍚戝浘锛屽彲鑳藉瓨鍦ㄩ噸杈瑰拰鑷幆锛屾墍鏈夎竟鏉冨潎涓烘鍊笺€? * 姹備粠1鍙风偣鍒皀鍙风偣鐨勬渶鐭窛绂伙紝鑻ヤ笉鍙揪鍒欒緭鍑?1銆? *
 * 瑙ｆ硶锛氭湸绱燚ijkstra绠楁硶锛岄€傜敤浜庣瀵嗗浘锛堣竟鏁癿鎺ヨ繎n虏锛? *   姣忔浠庢湭纭畾鏈€鐭窛绂荤殑鐐逛腑鎵惧嚭dist鏈€灏忕殑鐐箃锛? *   灏嗗叾鏍囪涓哄凡纭畾锛屽苟鐢╰鏇存柊鎵€鏈夐偦鎺ョ偣鐨刣ist銆? * 鏃堕棿澶嶆潅搴?O(n虏)
 *-----棰樼洰鍒嗘瀽-----*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 510;

int n, m;
int w[N][N];                                // 閭绘帴鐭╅樀锛寃[a][b]=a鍒癰鐨勮竟鏉?int dist[N];                                // dist[i]锛?鍙风偣鍒癷鍙风偣鐨勬渶鐭窛绂?bool st[N];                                 // st[i]锛歩鍙风偣鐨勬渶鐭窛绂绘槸鍚﹀凡纭畾

/*-----dijkstra鍑芥暟鍒嗘瀽-----*/
// 鏈寸礌Dijkstra锛氭瘡娆￠€塪ist鏈€灏忕殑鏈‘瀹氱偣锛岀敤鍏舵洿鏂伴偦灞?int dijkstra()
{
    memset(st, false, sizeof(st));
    memset(dist, 0x3f, sizeof(dist));       // 0x3f3f3f3f 鈮?1e9锛屼竴涓?澶ц€屼笉婧㈠嚭"鐨勫€?
    dist[1] = 0;                            // 璧风偣璺濈涓?

    /*-----杩唬 n-1 娆?----*/
    // 姣忔纭畾涓€涓偣鐨勬渶鐭窛绂伙紙鏈€鍚庝竴涓偣涓嶉渶瑕佹洿鏂板埆浜猴紝鎵€浠-1娆″嵆鍙級
    for (int i = 0; i < n - 1; i++)
    {
        /*-----绗竴姝ワ細浠庢墍鏈夋湭纭畾鐐逛腑鎵惧埌dist鏈€灏忕殑鐐箃-----*/
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            // 濡傛灉鐐筳鏈‘瀹?涓?(t==-1棣栨 鎴?dist[j] < dist[t])
            if (st[j] == false && (t == -1 || dist[t] > dist[j]))
            {
                t = j;
            }
        }

        if (t == -1) break;                 // 鎵€鏈夊彲杈剧偣閮藉凡纭畾锛堝墿浣欎笉鍙揪锛?        st[t] = true;                       // 鏍囪t鐨勬渶鐭窛绂诲凡纭畾

        /*-----绗簩姝ワ細鐢╰鏇存柊鎵€鏈夐偦鎺ョ偣鐨刣ist-----*/
        for (int j = 1; j <= n; j++)
        {
            // 鑻鏈‘瀹?涓?閫氳繃t鍒拌揪j姣斿綋鍓峝ist[j]鏇寸煭锛屽垯鏇存柊
            if (!st[j] && dist[t] + w[t][j] < dist[j])
            {
                dist[j] = dist[t] + w[t][j];
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;   // 涓嶅彲杈?    return dist[n];
}

int main()
{
    memset(w, 0x3f, sizeof(w));             // 閭绘帴鐭╅樀鍒濆鍖栦负"鏃犵┓澶?

    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        w[a][b] = min(w[a][b], c);          // 澶勭悊閲嶈竟锛氫繚鐣欐渶鐭殑閭ｆ潯
    }
    for (int i = 1; i <= n; i++)
    {
        w[i][i] = 0;                        // 鑷繁鍒拌嚜宸辩殑璺濈涓?
    }

    cout << dijkstra() << endl;
    return 0;
}