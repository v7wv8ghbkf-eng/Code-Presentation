/*-----棰樼洰鍒嗘瀽-----*/
// 杈撳叆N涓殗鍚庯紝浠绘剰涓や釜鐨囧悗涓嶈兘鍦ㄥ悓涓€琛屻€佸垪銆佸瑙掔嚎
// 妫嬬洏澶у皬绛変簬N * N
// 瑕佹眰杈撳嚭涓嶅悓鐨勬憜娉曪紝杈撳嚭椤哄簭浠ｈ〃浠?-n姣忎釜鐨囧悗鎵€鍦ㄥ垪搴忓彿
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int N = 15;

// 鐨囧悗涓暟锛屽叏灞€鍙橀噺鏂逛究鍑芥暟璋冪敤
int n;

/*-----dfs鍑芥暟鍒嗘瀽-----*/
// dfs锛氳緭鍑哄悇绉嶇殗鍚庢憜鏀剧殑瑙ｏ紝杩欎竴鐐逛笂鍜屽瓧绗?鏁板瓧鍏ㄦ帓鍒楁槸鏋佺浉浼肩殑锛?// 淇濇寔杩欎釜鎬濊矾锛屽疄闄呬笂鐨囧悗鐨勬憜鏀惧氨绛変环浜庢暟瀛?瀛楃鐨勬斁缃?// 鎵€浠ラ€掑綊褰㈠弬涔熸槸depth锛屽湪杩欓噷灏辨槸row锛堣搴忔暟锛夛紝琛ㄧず浠庣row琛屽紑濮?// 鍚屾牱鐨勶紝闇€瑕佸鏄炬暟缁勶紱arr[0~n-1]琛ㄧず绗?~n琛岀殗鍚庡垎鍒墍鍦ㄧ殑鍒楀簭鍙?&闇€瑕佸綋鍓嶈鍒楀瑙掔嚎鐨勭姸鎬佹潵鍒ゆ柇鑳戒笉鑳芥斁杩欎釜鐨囧悗
vector<int> arr;
bool used[N];
// bool鏁扮粍鍙兘淇濊瘉瀵规瘡涓锛屼笉鍚屽垪鏄惁鑳芥斁
// 鎵€浠ヨ繕闇€瑕佹鏌ュ瑙掔嚎鐨勬柟寮忥紝闇€瑕佸垎鍒瓨鏀惧悇涓鐨囧悗鐨勮鍒椾箣鍜屻€佷箣宸?涔熼渶瑕佸缃鏌ュ嚱鏁?int diag1[N], diag2[N];
inline bool isValid(int row, int col)
{
    int add = row + col;
    int minus = row - col;

    for (int i = 1; i <= n; i++)
    {
        if (used[i] && (diag1[i] == add || diag2[i] == minus))
        {
            return false;
        }
    }

    return true;
}
void dfs(int row)
{
    if (row == n + 1)
    {
        for (int x = 0; x < arr.size(); x++)
        {
            cout << arr[x];
        }
        cout << endl;
        return;
    }

    for (int col = 1; col <= n; col++)
    {
        if (!used[col] && isValid(row, col))
        {
            arr.push_back(col);
            used[col] = true;
            diag1[col] = row + col;
            diag2[col] = row - col;
            dfs(row + 1);
            arr.pop_back();
            used[col] = false;
            diag1[col] = -1;
            diag2[col] = -1;
        }
    }
}

int main()
{
    memset(used, false, sizeof used);
    memset(diag1, -1, sizeof diag1);
    memset(diag2, -1, sizeof diag2);

    cin >> n;
    dfs(1);
    return 0;
}