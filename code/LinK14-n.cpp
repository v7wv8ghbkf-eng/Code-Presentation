/*-----棰樼洰鍒嗘瀽-----
 * 鍏殗鍚庣n涓В锛?脳8妫嬬洏涓婃斁缃?涓殗鍚庝娇鍏朵簰涓嶆敾鍑伙紝鍏辨湁92缁勮В銆? * 姣忕粍瑙ｇ敤8浣嶆暟瀛椾覆琛ㄧず锛堢i浣?绗琲琛岀殗鍚庢墍鍦ㄥ垪鍙凤級銆? * 杈撳叆T缁勬暟鎹紝姣忕粍n(1鈮鈮?2)锛岃緭鍑烘寜瀛楀吀搴忕n灏忕殑鐨囧悗涓层€? *
 * 瑙ｆ硶锛欴FS鍥炴函鐢熸垚鎵€鏈?2瑙ｏ紙鎸夊垪鍙?鈫?鏋氫妇鑷劧淇濊瘉瀛楀吀搴忥級锛? *       瀛樺叆鏁扮粍锛孫(1)鏌ヨ杈撳嚭銆? *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int col[9];                                 // col[row]锛氱row琛岀殗鍚庢墍鍦ㄥ垪锛?~8锛?bool used[9];                               // used[c]锛氱c鍒楁槸鍚﹁鍗犵敤
vector<int> solutions;                      // 鎵€鏈?2涓В锛堟暣鏁板舰寮忥紝澶╃劧瀛楀吀搴忥級

/*-----check锛氭鏌?row, c)鏄惁涓庡凡鏀剧疆鐨囧悗鍐茬獊-----*/
bool check(int row, int c) {
    for (int i = 1; i < row; i++)
        if (abs(row - i) == abs(c - col[i]))
            return false;                   // 瀵硅绾垮啿绐侊細琛屽樊==鍒楀樊
    return true;
}

/*-----dfs锛氶€愯鏀剧疆鐨囧悗锛岀敓鎴愬叏閮ㄨВ-----*/
void dfs(int row) {
    if (row > 8) {                          // 8琛屾斁缃畬姣曪紝璁板綍杩欎竴缁勮В
        int num = 0;
        for (int i = 1; i <= 8; i++)
            num = num * 10 + col[i];        // 鎷兼帴涓?浣嶆暣鏁?        solutions.push_back(num);
        return;
    }
    for (int c = 1; c <= 8; c++) {          // 1鈫?鏋氫妇淇濊瘉瀛楀吀搴?        if (!used[c] && check(row, c)) {
            used[c] = true; col[row] = c;
            dfs(row + 1);
            used[c] = false;                // 鍥炴函
        }
    }
}

int main() {
    dfs(1);                                 // 棰勭敓鎴愬叏閮?2瑙?
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << solutions[n - 1] << endl;   // 涓嬫爣0瀵瑰簲绗?涓В
    }
    return 0;
}