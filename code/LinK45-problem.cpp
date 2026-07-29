/*-----棰樼洰鍒嗘瀽-----
 * 鏁扮嫭楠岃瘉锛氱粰瀹氫竴涓?脳9鐭╅樀浣滀负"璁板繂纰庣墖"锛屽垽瀹氬畠鏄惁鏄垵濮嬬煩闃礎鐨勬湁鏁堣В銆? * 鍒濆鐭╅樀A锛?脳9锛変腑0琛ㄧず绌烘牸锛岄渶瑕佸～鍏?-9浣挎瘡琛屻€佹瘡鍒椼€佹瘡涓?脳3瀹牸鍐呮暟瀛椾笉閲嶅銆? * 杈撳叆鐨勭煩闃佃嫢婊¤冻锛氫笌鍒濆鐭╅樀A鐨勫凡鐭ユ暟瀛椾笉鍐茬獊锛堝嵆闈?浣嶇疆涓嶅彉锛夛紝
 *   涓旀瘡琛屻€佹瘡鍒椼€佹瘡涓鏍煎唴鏃犻噸澶嶆暟瀛楋紙0绌烘牸闄ゅ锛夛紝鍒欎负鏈夋晥瑙ｈ緭鍑?Yes"锛屽惁鍒?No"銆? *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 9;                        // 鏁扮嫭澶у皬 9脳9
const int M = 3;                        // 瀹牸澶у皬 3脳3

// 鍒濆鐭╅樀A锛?琛ㄧず绌烘牸锛岄渶濉叆1-9锛?string memory[N] = {"530070000",
                    "600195000",
                    "098000060",
                    "800060003",
                    "400803001",
                    "700020006",
                    "060000280",
                    "000419005",
                    "000080079"};

int a[N][N], b[N][N];                   // a:鍒濆鐭╅樀锛宐:杈撳叆鐭╅樀
bool st[N + 1];                         // 鏁板瓧鏍囪鏁扮粍锛?~9锛?
/*-----check_input锛氶獙璇佽緭鍏ユ牸寮?----*/
// 璇诲叆9琛屽瓧绗︿覆锛屾瘡琛屽繀椤绘槸鎭板ソ9涓暟瀛楀瓧绗︼紙'0'~'9'锛?bool check_input()
{
    string line;
    for (int i = 0; i < N; i++)
    {
        cin >> line;
        if (line.size() != N)           // 琛岄暱搴︿笉瀵癸紙濡傛牱渚?鏌愯杩囬暱锛?            return false;

        for (int j = 0; j < N; j++)
        {
            int t = line[j] - '0';
            if (t < 0 || t > N)         // 闈炴暟瀛楀瓧绗?                return false;
            b[i][j] = t;                // 瀛樺叆 b 鐭╅樀
        }
    }
    return true;
}

/*-----check_row锛氭鏌ユ瘡琛屾槸鍚︽湁閲嶅鏁板瓧-----*/
bool check_row()
{
    for (int i = 0; i < N; i++)
    {
        memset(st, false, sizeof(st));
        for (int j = 0; j < N; j++)
        {
            int t = b[i][j];
            if (t < 0 || t > N) return false;
            if (t == 0) continue;       // 0 琛ㄧず绌烘牸锛岃烦杩囨鏌?            if (st[t] == true)          // 鏁板瓧t宸插湪鏈鍑虹幇杩?                return false;
            st[t] = true;
        }
    }
    return true;
}

/*-----check_col锛氭鏌ユ瘡鍒楁槸鍚︽湁閲嶅鏁板瓧-----*/
bool check_col()
{
    for (int i = 0; i < N; i++)
    {
        memset(st, false, sizeof(st));
        for (int j = 0; j < N; j++)
        {
            int t = b[j][i];            // 娉ㄦ剰锛氳绱㈠紩涓簀锛屽垪绱㈠紩涓篿
            if (t < 0 || t > N) return false;
            if (t == 0) continue;
            if (st[t] == true)
                return false;
            st[t] = true;
        }
    }
    return true;
}

/*-----check_block锛氭鏌ユ瘡涓?脳3瀹牸鏄惁鏈夐噸澶嶆暟瀛?----*/
bool check_block()
{
    for (int i = 0; i < N; i += M)          // 瀹牸琛岃捣鐐癸細0, 3, 6
    {
        for (int j = 0; j < N; j += M)      // 瀹牸鍒楄捣鐐癸細0, 3, 6
        {
            memset(st, false, sizeof(st));
            for (int dx = 0; dx < M; dx++)
            {
                for (int dy = 0; dy < M; dy++)
                {
                    int t = b[i + dx][j + dy];
                    if (t < 0 || t > N) return false;
                    if (t == 0) continue;
                    if (st[t] == true)
                        return false;
                    st[t] = true;
                }
            }
        }
    }
    return true;
}

int main()
{
    // 灏嗗垵濮嬬煩闃礎鐨勫瓧绗︿覆杞负鏁存暟瀛樺埌 a 鏁扮粍
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            a[i][j] = memory[i][j] - '0';
        }
    }

    // 杈撳叆楠岃瘉锛氭牸寮忔纭槸绗竴姝?    if (!check_input())
    {
        cout << "No" << endl;
        return 0;
    }

    // 涓夋楠岃瘉锛氳 鈫?鍒?鈫?瀹牸锛屽叏閮ㄩ€氳繃鎵嶆槸鏈夋晥瑙?    if (check_row() && check_col() && check_block())
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}