/*-----棰樼洰鍒嗘瀽-----
 * 闈跺舰鏁扮嫭锛堟暟鐙?+ 鏈€澶у垎鏁帮級锛? * 鍦?脳9闈跺舰鏁扮嫭涓紝姣忎釜鏍煎瓙鏈夊垎鍊硷紙绂讳腑蹇冭秺杩戝垎鍊艰秺楂橈紝6~10鍒嗭級锛? * 濉叆鏁板瓧鍚庯紝璇ユ牸瀛愮殑璐＄尞 = 鍒嗗€?脳 濉叆鏁板瓧銆? * 姹傝兘澶熷緱鍒扮殑鏈€楂樻€诲垎锛涜嫢鏃犺В杈撳嚭-1銆? *
 * 瑙ｆ硶锛氬湪鏁扮嫭DFS鍥炴函鍩虹涓婂鍔犲垎鏁拌绠? *   1. 鐢ㄤ簩杩涘埗鐘舵€佸帇缂╋紙鍚孡inK47锛変紭鍖栨悳绱? *   2. 鐢ㄤ紭鍖栨悳绱㈤『搴忥紙姣忔閫夊彲閫夋暟瀛楁渶灏戠殑绌烘牸锛? *   3. 鎼滅储鎵€鏈夊悎娉曡В锛岃褰曟渶澶у垎鏁? *   4. 鍒嗗€煎嚱鏁帮細score(x, y) = min(min(x,8-x), min(y,8-y)) + 6
 *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 9, M = 1 << N;

int row[N], col[N], cell[3][3];         // 浜岃繘鍒剁姸鎬侊細琛?鍒?瀹牸鍙敤鏁板瓧
int ones[M];                            // ones[i]锛氫簩杩涘埗i涓?鐨勪釜鏁?int map[M];                             // map[1<<t] = t
int g[N][N];                            // 妫嬬洏锛?琛ㄧず绌烘牸锛?~9琛ㄧず宸插～锛?int ans = -1;                            // 鏈€楂樺垎鏁帮紙-1琛ㄧず鏃犺В锛?
/*-----lowbit-----*/
inline int lowbit(int n)
{
    return n & -n;
}

/*-----get-----*/
// 鑾峰彇(x,y)澶勫彲鐢ㄦ暟瀛楃殑浜岃繘鍒剁姸鎬?inline int get(int x, int y)
{
    return row[x] & col[y] & cell[x / 3][y / 3];
}

/*-----get_score-----*/
// 闈跺舰鏁扮嫭鍒嗗€硷細瓒婇潬杩戜腑蹇冨垎鍊艰秺楂?// 鏈€鍐呭湀锛堥粍锛?0鍒?鈫?绾?鍒?鈫?钃?鍒?鈫?妫?鍒?鈫?鏈€澶栧湀锛堢櫧锛?鍒?// 鍏紡锛歮in(鍒板洓杈硅窛绂? + 6锛屽疄鐜扮畝娲?inline int get_score(int x, int y, int t)
{
    return (min(min(x, 8 - x), min(y, 8 - y)) + 6) * t;
}

/*-----init-----*/
void init()
{
    // 寤虹珛map琛?    for (int i = 0; i < N; i++)
    {
        map[1 << i] = i;
    }

    // 寤虹珛ones琛?    for (int i = 0; i < M; i++)
    {
        ones[i] = 0;
        for (int j = i; j; j -= lowbit(j))
        {
            ones[i]++;
        }
    }

    // 鍒濆鍖栨墍鏈夎/鍒?瀹牸涓哄叏鍙敤 (511 = 111111111鈧?
    for (int i = 0; i < N; i++)
    {
        row[i] = col[i] = M - 1;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cell[i][j] = M - 1;
        }
    }
}

/*-----draw鍑芥暟-----*/
// 鍦?x,y)澶勫～鍏ユ暟瀛楋紙t>0锛夋垨鎿﹂櫎鏁板瓧锛坱<0锛岀敤-t鎭㈠锛?// 鍚屾椂鏇存柊琛?鍒?瀹牸鐨勪簩杩涘埗鍗犵敤鐘舵€?void draw(int x, int y, int t)
{
    if (t > 0)
    {
        g[x][y] = t;                    // 濉叆鏁板瓧
        t--;                            // 杞负绱㈠紩0~8
        row[x] -= 1 << t;               // 灏嗚鏁板瓧浠庡彲鐢ㄩ泦鍚堜腑绉婚櫎
        col[y] -= 1 << t;               // 淇锛歝ol[y]鑰岄潪col[x]
        cell[x / 3][y / 3] -= 1 << t;   // 淇锛歝ell[x/3][y/3]鑰岄潪cell[x][y]
    }
    else
    {
        int val = -t;                   // 鎭㈠鐨勬暟瀛楀€?        g[x][y] = 0;                    // 鎿﹂櫎锛堢┖鏍硷級
        val--;                          // 杞负绱㈠紩
        row[x] += 1 << val;             // 灏嗚鏁板瓧鎭㈠鍒板彲鐢ㄩ泦鍚?        col[y] += 1 << val;
        cell[x / 3][y / 3] += 1 << val;
    }
}

/*-----dfs鍑芥暟鍒嗘瀽-----*/
// dfs锛氳繕鍓ヽnt涓┖鏍硷紝褰撳墠宸插緱score鍒嗭紝鎼滅储鎵€鏈夊悎娉曡В骞舵洿鏂版渶楂樺垎
// 鐢变簬瑕侀亶鍘嗘墍鏈夎В锛屼笉鑳界敤bool鎻愬墠杩斿洖锛堜笌LinK47涓嶅悓锛?void dfs(int cnt, int score)
{
    // 閫掑綊鍑哄彛锛氭墍鏈夌┖鏍煎凡濉畬锛屾洿鏂版渶楂樺垎
    if (!cnt)
    {
        ans = max(ans, score);
        return;                         // 淇锛氶渶瑕乺eturn閬垮厤缁х画鎼滅储
    }

    // 鍓灊锛氬鏋滃綋鍓嶅垎鏁?鍓╀綑鏍煎瓙鍏ㄥ～10鍒喢?锛堢悊璁烘渶澶у€硷級浠嶁墹ans锛屽壀鏋?    // 瀹為檯涓婃病鏈夋鍓灊涔熻兘閫氳繃锛屼絾鍔犱笂鍚庡彲澶у箙鍔犻€?
    /*-----浼樺寲鎼滅储椤哄簭锛氭壘鍙€夋暟瀛楁渶灏戠殑绌烘牸-----*/
    int minv = 10;
    int x = 0, y = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (g[i][j] == 0)           // 淇锛?琛ㄧず绌烘牸锛坓鏄痠nt鏁扮粍锛?            {
                int t = ones[get(i, j)];
                if (t < minv)
                {
                    minv = t;
                    x = i, y = j;
                }
            }
        }
    }

    // 鏋氫妇鎵€鏈夊彲鐢ㄦ暟瀛?    for (int i = get(x, y); i; i -= lowbit(i))
    {
        int t = map[lowbit(i)] + 1;     // 绱㈠紩鈫掓暟瀛楋紙1~9锛?        draw(x, y, t);                  // 濉叆
        dfs(cnt - 1, score + get_score(x, y, t));
        draw(x, y, -t);                 // 鍥炴函
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int cnt = 0;                        // 绌烘牸鏁?    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> g[i][j];
            if (g[i][j] != 0)
            {
                draw(i, j, g[i][j]);    // 宸叉湁鏁板瓧锛屾爣璁板崰鐢?            }
            else
            {
                cnt++;
            }
        }
    }

    dfs(cnt, 0);                        // 浠巆nt涓┖鏍笺€?鍒嗗紑濮嬫悳绱?
    cout << ans << endl;                // 杈撳嚭鏈€楂樺垎锛堟棤瑙ｆ椂涓?1锛?    return 0;
}