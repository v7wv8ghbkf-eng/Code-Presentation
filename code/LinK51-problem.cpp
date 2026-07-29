/*-----棰樼洰鍒嗘瀽-----
 * 杩峰杩為€氬尯鍩熻鏁帮紙BFS娉涙椽濉厖锛夛細
 * 缁欏畾H脳W鐨勮糠瀹紝'@'鏄捣鐐癸紝'.'鏄彲閫氳鍖哄煙锛?#'鏄澹併€? * 浠庤捣鐐瑰嚭鍙戯紝姣忔鍙悜涓婁笅宸﹀彸绉诲姩涓€鏍硷紝姹傝兘鍒拌揪鐨勫尯鍩熸€绘暟锛堝惈璧风偣锛夈€? * 澶氱粍鏁版嵁锛屼互"0 0"缁撴潫銆? *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 25;
int row, col;                           // 娉ㄦ剰锛歳ow=H(琛屾暟), col=W(鍒楁暟)
char g[N][N];                           // 鍦板浘

int dx[] = {1, -1, 0, 0};              // 鍥涗釜鏂瑰悜鐨勫亸绉婚噺
int dy[] = {0, 0, 1, -1};

/*-----bfs鍑芥暟鍒嗘瀽-----*/
// BFS娉涙椽濉厖锛氫粠璧风偣(x,y)鍑哄彂锛屽皢鎵€鏈夊彲杈剧殑'.'鏍囪涓?#'锛堝凡璁块棶锛夛紝缁熻鎬绘牸鏁?// 涓嶉渶瑕侀澶栫殑st鏁扮粍锛岀洿鎺ヤ慨鏀瑰湴鍥惧嵆鍙?int bfs(int x, int y)
{
    queue<PII> q;

    g[x][y] = '#';                      // 鏍囪璧风偣涓哄凡璁块棶
    q.push({x, y});
    int res = 0;

    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        res++;                          // 姣忓嚭闃熶竴涓牸瀛愶紝璁℃暟+1

        for (int i = 0; i < 4; i++)
        {
            int X = t.first + dx[i];
            int Y = t.second + dy[i];

            if (X < 0 || X >= row || Y < 0 || Y >= col)
                continue;               // 瓒婄晫
            if (g[X][Y] == '#')
                continue;               // 澧欏鎴栧凡璁块棶

            q.push({X, Y});
            g[X][Y] = '#';              // 鍏ラ槦鍗虫爣璁帮紝閬垮厤閲嶅鍏ラ槦
        }
    }

    return res;
}

int main()
{
    // 杈撳叆鏍煎紡锛氬厛鍒楁暟W(col) 鍚庤鏁癏(row)
    while (cin >> col >> row && (col && row))
    {
        int x, y;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> g[i][j];
                if (g[i][j] == '@')     // 璁板綍璧风偣鍧愭爣
                {
                    x = i, y = j;
                }
            }
        }

        cout << bfs(x, y) << endl;
    }
    return 0;
}