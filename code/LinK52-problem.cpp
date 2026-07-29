/*-----棰樼洰鍒嗘瀽-----
 * 鏈哄櫒浜哄彲杈捐寖鍥达紙BFS + 鏁颁綅鍜岀害鏉燂級锛? * 鍦╩脳n鐨勭綉鏍间腑锛屼粠(0,0)鍑哄彂锛屾瘡娆″悜涓婁笅宸﹀彸绉诲姩涓€鏍硷紝
 * 浣嗕笉鑳借繘鍏ヨ鍧愭爣鍜屽垪鍧愭爣鐨勬暟浣嶄箣鍜屽ぇ浜巏鐨勬牸瀛愩€? * 姹傝兘鍒拌揪澶氬皯涓牸瀛愩€? *
 * 鏁颁綅鍜岋細渚嬪(35,37)锛?+5+3+7=18锛岃嫢k鈮?8鍒欏彲杩涘叆锛屽惁鍒欎笉鑳姐€? * 绾︽潫锛?鈮鈮?00锛?鈮鈮?0锛?鈮鈮?0
 *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 110;

typedef pair<int, int> PII;
int m, n;                               // m琛宯鍒?bool st[N][N];                          // 璁块棶鏍囪锛堟瘡涓狟FS鍙敤涓€娆★紝涓嶉渶閲嶇疆锛?
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

/*-----get_plus鍑芥暟-----*/
// 璁＄畻鏁存暟x鐨勫悇鏁颁綅涔嬪拰锛堜緥濡?8鈫?+8=9锛?inline int get_plus(int x)
{
    int res = 0;
    while (x)
    {
        res += x % 10;                  // 鍙栦釜浣?        x /= 10;                        // 鍘绘帀涓綅
    }
    return res;
}

/*-----bfs鍑芥暟鍒嗘瀽-----*/
// BFS浠?sx,sy)鍑哄彂锛屾帰绱㈡墍鏈夋弧瓒?鏁颁綅鍜屸墹k"鐨勬牸瀛?// 鐢变簬绾︽潫鏄暟浣嶅拰闃堝€硷紝鍚堟硶鍖哄煙鏄繛閫氱殑锛堜粠鍘熺偣寮€濮嬶級锛孊FS涓嶄細婕忔帀
int bfs(int sx, int sy, int k)
{
    memset(st, false, sizeof(st));      // 姣忔BFS閲嶆柊鍒濆鍖栬闂爣璁?    queue<PII> q;
    int res = 0;
    q.push({sx, sy});
    st[sx][sy] = true;

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        res++;                          // 璁℃暟鍙揪鏍煎瓙

        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];

            if (x < 0 || x >= m || y < 0 || y >= n)
                continue;               // 瓒婄晫
            // 鏁颁綅鍜岃秴杩噆 鎴?宸茶闂紝璺宠繃
            if (get_plus(x) + get_plus(y) > k || st[x][y])
                continue;

            q.push({x, y});
            st[x][y] = true;
        }
    }

    return res;
}

int main()
{
    int k;
    cin >> k >> m >> n;

    cout << bfs(0, 0, k) << endl;
    return 0;
}