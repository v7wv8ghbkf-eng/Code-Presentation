/*-----棰樼洰鍒嗘瀽-----
 * 婊氱煶鏌憋紙Bloxorz锛夛細涓€涓?脳1脳2鐨勯暱鏂逛綋鐭虫煴鍦∟脳M鐨勮糠瀹腑婊氬姩銆? * 鐭虫煴鏈?绉嶇姸鎬侊細绔嬬潃(0)銆佹í韬?1)銆佺珫韬?2)銆? * 闇€瑕佹粴鍔ㄥ埌鐩爣浣嶇疆'O'涓婁笖鐘舵€佷负绔嬬潃锛屾眰鏈€灏戞鏁帮紱鏃犺В杈撳嚭"Impossible"銆? *
 * 瑙ｆ硶锛欱FS锛堢姸鎬佷负 (x, y, st) 涓夊厓缁勶級
 *   st=0锛堢珛锛夛細鍗犳嵁1鏍?(x,y)锛屼笉鑳界珛鍦?E'涓? *   st=1锛堟í韬猴級锛氬崰鎹?鏍?(x,y)鍜?x,y+1)
 *   st=2锛堢珫韬猴級锛氬崰鎹?鏍?(x,y)鍜?x+1,y)
 *
 * 澶氱粍娴嬭瘯鏁版嵁锛屼互"0 0"缁撴潫銆? * 鏁版嵁鑼冨洿锛? 鈮?N, M 鈮?500
 *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 510;

int row, col;
char area[N][N];

/*-----鐭虫煴鐘舵€佺粨鏋?----*/
// st=0锛氱珛鐫€ (x,y)
// st=1锛氭í韬猴紝鍗犳嵁(x,y)鍜?x,y+1)
// st=2锛氱珫韬猴紝鍗犳嵁(x,y)鍜?x+1,y)
struct Stone {
    int x, y, st;
};
Stone src, dst;                             // 璧风偣鍜岀粓鐐?
/*-----isInside-----*/
// 鍒ゆ柇鍧愭爣鏄惁鍦ㄨ糠瀹寖鍥村唴
inline bool isInside(int x, int y) {
    return x >= 0 && x < row && y >= 0 && y < col;
}

/*-----isValid-----*/
// 鍒ゆ柇鐭虫煴褰撳墠鐘舵€佹槸鍚﹀悎娉?// 瑙勫垯锛氫笉鑳芥湁浠讳綍閮ㄤ綅鍦ㄧ鍦?#'涓婏紱绔嬬潃鏃朵笉鑳界珯鍦ㄦ槗纰庡湴'E'涓?inline bool isValid(Stone s) {
    // 鍩烘湰妫€鏌ワ細涓诲潗鏍囧繀椤诲湪鐣屽唴涓旈潪绂佸湴
    if (!isInside(s.x, s.y) || area[s.x][s.y] == '#') return false;

    // 妯汉锛氬彸杈归偅鏍间篃蹇呴』鍦ㄧ晫鍐呬笖闈炵鍦?    if (s.st == 1 && (!isInside(s.x, s.y + 1) || area[s.x][s.y + 1] == '#'))
        return false;

    // 绔栬汉锛氫笅杈归偅鏍间篃蹇呴』鍦ㄧ晫鍐呬笖闈炵鍦?    if (s.st == 2 && (!isInside(s.x + 1, s.y) || area[s.x + 1][s.y] == '#'))
        return false;

    // 绔嬬潃鏃朵笉鑳界珯鍦ㄦ槗纰庡湴闈笂
    if (s.st == 0 && area[s.x][s.y] == 'E') return false;

    return true;
}

/*-----nextState锛氳绠楁粴鍔ㄥ悗鐨勭姸鎬?----*/
// 瀵圭煶鏌辨墽琛屽悜(dir)鏂瑰悜婊氬姩锛宒ir: 0=鍙? 1=宸? 2=涓? 3=涓?// 杩斿洖婊氬姩鍚庣殑鏂扮姸鎬侊紙涓嶆鏌ュ悎娉曟€э紝鐢辫皟鐢ㄨ€呮鏌ワ級
Stone nextState(Stone s, int dir) {
    Stone nxt;
    if (s.st == 0) {                        // 褰撳墠绔嬬潃
        if (dir == 0)      nxt = {s.x, s.y + 1, 1};  // 鍚戝彸婊?鈫?妯汉
        else if (dir == 1) nxt = {s.x, s.y - 2, 1};  // 鍚戝乏婊?鈫?妯汉
        else if (dir == 2) nxt = {s.x + 1, s.y, 2};  // 鍚戜笅婊?鈫?绔栬汉
        else               nxt = {s.x - 2, s.y, 2};  // 鍚戜笂婊?鈫?绔栬汉
    } else if (s.st == 1) {                 // 褰撳墠妯汉
        if (dir == 0)      nxt = {s.x, s.y + 2, 0};  // 鍚戝彸婊?鈫?绔嬬潃
        else if (dir == 1) nxt = {s.x, s.y - 1, 0};  // 鍚戝乏婊?鈫?绔嬬潃
        else if (dir == 2) nxt = {s.x + 1, s.y, 1};  // 鍚戜笅婊?鈫?妯汉
        else               nxt = {s.x - 1, s.y, 1};  // 鍚戜笂婊?鈫?妯汉
    } else {                                // 褰撳墠绔栬汉 (s.st == 2)
        if (dir == 0)      nxt = {s.x, s.y + 1, 2};  // 鍚戝彸婊?鈫?绔栬汉
        else if (dir == 1) nxt = {s.x, s.y - 1, 2};  // 鍚戝乏婊?鈫?绔栬汉
        else if (dir == 2) nxt = {s.x + 2, s.y, 0};  // 鍚戜笅婊?鈫?绔嬬潃
        else               nxt = {s.x - 1, s.y, 0};  // 鍚戜笂婊?鈫?绔嬬潃
    }
    return nxt;
}

/*-----BFS-----*/
// dist[x][y][st]锛氬埌杈剧姸鎬?x,y,st)鐨勬渶灏戞鏁帮紝-1琛ㄧず鏈闂?int dist[N][N][3];

int bfs() {
    memset(dist, -1, sizeof(dist));
    queue<Stone> q;

    dist[src.x][src.y][src.st] = 0;
    q.push(src);

    while (!q.empty()) {
        Stone cur = q.front();
        q.pop();

        // 鍒拌揪鐩爣锛氱珛鐫€绔欏湪'O'涓?        if (cur.st == 0 && area[cur.x][cur.y] == 'O')
            return dist[cur.x][cur.y][cur.st];

        for (int dir = 0; dir < 4; dir++) {
            Stone nxt = nextState(cur, dir);
            if (!isValid(nxt)) continue;    // 闈炴硶鐘舵€佽烦杩?            if (dist[nxt.x][nxt.y][nxt.st] != -1) continue;  // 宸茶闂?
            dist[nxt.x][nxt.y][nxt.st] = dist[cur.x][cur.y][cur.st] + 1;
            q.push(nxt);
        }
    }

    return -1;                              // 鏃犺В
}

/*-----build_map-----*/
// 璇诲彇鍦板浘锛屽畾浣嶈捣鐐瑰拰缁堢偣
void build_map() {
    for (int i = 0; i < row; i++) {
        cin >> area[i];
    }

    src.st = -1;                            // 鏍囪鏈壘鍒拌捣鐐?    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (area[i][j] == '#') continue;

            if (area[i][j] == 'X') {
                // 璧风偣锛氭鏌ユ槸鍗曠嫭涓€涓猉杩樻槸涓や釜鐩搁偦鐨刋
                if (src.st == -1) {
                    // 鍚戝彸妫€鏌ユ槸鍚︽í韬?                    if (j + 1 < col && area[i][j + 1] == 'X') {
                        src = {i, j, 1};    // 妯汉璧风偣
                    }
                    // 鍚戜笅妫€鏌ユ槸鍚︾珫韬?                    else if (i + 1 < row && area[i + 1][j] == 'X') {
                        src = {i, j, 2};    // 绔栬汉璧风偣
                    }
                    else {
                        src = {i, j, 0};    // 绔嬬潃璧风偣
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> row >> col && row && col) {
        build_map();

        int ans = bfs();
        if (ans == -1)
            cout << "Impossible" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}