/*-----棰樼洰鍒嗘瀽-----
 * 楠戝＋鏁戝叕涓伙紙8鏂瑰悜BFS鏈€鐭矾寰勶級锛? * 鍦╮ow脳col鐨勬鐩樹笂锛岄獞澹?'K')闇€瑕佸埌杈惧叕涓荤殑浣嶇疆('H')锛?*'鏄殰纰嶃€? * 楠戝＋姣忔鍙互鍚?涓┈姝ユ柟鍚戠Щ鍔紙鏃ュ瓧褰級锛屾眰鏈€鐭鏁般€? *
 * 瑙ｆ硶锛欱FS澶╃劧淇濊瘉棣栨鍒拌揪鐩爣鏃剁殑璺濈鍗充负鏈€鐭窛绂? *-----棰樼洰鍒嗘瀽-----*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

typedef pair<int, int> PII;

const int N = 155;

int col, row;
char g[N][N];                           // 鍦板浘锛?K'璧风偣锛?H'缁堢偣锛?*'闅滅锛?.'绌哄湴
int dist[N][N];                         // 璺濈鏁扮粍锛?1琛ㄧず鏈闂?PII start;                              // 楠戝＋璧风偣
PII ending;                             // 鍏富浣嶇疆

// 8鏂瑰悜椹锛堟棩瀛楀舰锛夛細(卤2,卤1) 鍜?(卤1,卤2) 鐨勭粍鍚?int dx[] = {1, -1, 1, -1, 2, -2, 2, -2};
int dy[] = {2, 2, -2, -2, 1, 1, -1, -1};

/*-----bfs鍑芥暟鍒嗘瀽-----*/
// BFS浠庤捣鐐规悳绱紝鎵惧埌缁堢偣鍗宠繑鍥炴渶鐭窛绂?// 鐢变簬BFS鎸夊眰鎵╁睍锛岄娆￠亣鍒扮粓鐐规椂鐨刣ist鍗充负鏈€鐭矾寰勯暱搴?int bfs(PII start, PII end)
{
    memset(dist, -1, sizeof(dist));     // 鍒濆鍖栨墍鏈夎窛绂讳负-1锛堟湭璁块棶锛?
    queue<PII> q;
    q.push({start.first, start.second});
    dist[start.first][start.second] = 0;

    while (!q.empty())
    {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int x = dx[i] + t.first, y = dy[i] + t.second;

            if (x < 0 || x >= row || y < 0 || y >= col) continue;   // 瓒婄晫
            if (g[x][y] == '*') continue;                            // 闅滅
            if (dist[x][y] != -1) continue;                          // 宸茶闂?
            // 鍒版柊鏍煎瓙鐨勮窛绂?= 鍒板綋鍓嶆牸瀛愯窛绂?+ 1
            dist[x][y] = dist[t.first][t.second] + 1;

            // 濡傛灉鍒拌揪缁堢偣锛岀洿鎺ヨ繑鍥炴渶鐭窛绂?            if (make_pair(x, y) == end) return dist[x][y];

            q.push({x, y});
            g[x][y] = '*';              // 鏍囪涓哄凡璁块棶锛堜慨鏀瑰湴鍥撅紝鏃犻渶棰濆st鏁扮粍锛?        }
    }

    return -1;                          // 鏃犳硶鍒拌揪锛堥鐩繚璇佹湁瑙ｏ紝姝よ涓嶄細鎵ц锛?}

int main()
{
    cin >> col >> row;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'K')         // 楠戝＋璧风偣
            {
                start.first = i;
                start.second = j;
            }
            if (g[i][j] == 'H')         // 鍏富浣嶇疆锛堢粓鐐癸級
            {
                ending.first = i;
                ending.second = j;
            }
        }
    }

    cout << bfs(start, ending) << endl;
    return 0;
}