/*-----棰樼洰鍒嗘瀽-----
 * 椹蛋鏃ワ紙8鏂瑰悜BFS鏈€杩滆窛绂伙級锛? * 鍦╮ow脳col鐨勬鐩樹笂锛屼粠璧风偣鍑哄彂锛屾瘡娆″彲鍚?涓┈姝ユ柟鍚戠Щ鍔紙鏃ュ瓧褰級锛? * 涓嶅彲璧板嚭妫嬬洏鎴栫粡杩囬殰纰?'*')銆傛眰浠庤捣鐐瑰埌浠绘剰鍙揪鏍煎瓙鐨勬渶杩滆窛绂伙紙姝ユ暟锛夈€? *
 * 杈撳叆锛歝ol row start_x start_y锛岀劧鍚庢槸妫嬬洏锛?.'绌哄湴锛?*'闅滅锛? * 娉ㄦ剰锛氳緭鍏ラ『搴忔槸鍏坈ol(鍒?鍚巖ow(琛?锛屼笖鍧愭爣浠?寮€濮? *-----棰樼洰鍒嗘瀽-----*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 110;
int row, col;
PII start;                              // 璧风偣鍧愭爣
char g[N][N];                           // 鍦板浘锛?-indexed锛?int dist[N][N];                         // dist[x][y]锛氳捣鐐瑰埌(x,y)鐨勬渶鐭窛绂?
// 8鏂瑰悜椹锛氭棩瀛楀舰绉诲姩锛堝厛鐩磋蛋鍐嶆枩璧帮級
const int dx[] = {1, -1, 1, -1, 0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

/*-----bfs鍑芥暟鍒嗘瀽-----*/
// BFS姹備粠璧风偣鍑哄彂鍒版墍鏈夊彲杈炬牸瀛愮殑鏈€杩滆窛绂?// 鐢变簬BFS澶╃劧鎸夎窛绂诲垎灞傦紝姣忓眰璺濈+1锛屾渶缁堥亶鍘嗗埌鐨勬渶澶ist鍗充负鏈€杩滆窛绂?int bfs()
{
    memset(dist, -1, sizeof(dist));     // -1琛ㄧず鏈闂?
    queue<PII> q;
    q.push(start);
    dist[start.first][start.second] = 0;

    int res = 0;                        // 璁板綍鏈€杩滆窛绂?    while (q.size())
    {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];

            // 妫嬬洏鍧愭爣浠?寮€濮嬪埌row/col
            if (x < 1 || x > row || y < 1 || y > col) continue;
            if (g[x][y] == '*' || dist[x][y] != -1) continue;  // 闅滅鎴栧凡璁块棶

            // 鏂版牸瀛愮殑璺濈 = 鍓嶄竴鏍艰窛绂?+ 1
            dist[x][y] = dist[t.first][t.second] + 1;
            res = max(res, dist[x][y]); // 鏇存柊鏈€杩滆窛绂?            q.push(make_pair(x, y));
        }
    }

    return res;                         // 娉ㄦ剰锛氳嫢娌℃湁鍙揪鏍煎瓙锛堥櫎璧风偣锛夛紝杩斿洖0
}

int main()
{
    // 杈撳叆椤哄簭锛氬垪col 琛宺ow 璧风偣_x 璧风偣_y
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