/*-----棰樼洰鍒嗘瀽-----
 * 浜岃繘鍒跺瘑鐮侀攣锛歯涓寜閽?n<30)锛?=鍑癸紝1=鍑搞€傛寜涓€涓寜閽細鍙嶈浆鑷韩鍙婄浉閭绘寜閽€? * 缁欏畾鍒濆鍜岀洰鏍囩姸鎬侊紝姹傛渶灏戞寜鎸夐挳娆℃暟锛涙棤瑙ｈ緭鍑?impossible"銆? *
 * 瑙ｆ硶锛氭灇涓?璐績銆傜涓€涓寜閽寜/涓嶆寜鍐冲畾浜嗘暣涓簭鍒楃殑鍚庣画鎿嶄綔鈥斺€? *   褰撲粠宸﹀埌鍙冲鐞嗗埌绗琲浣嶆椂锛岀i-1浣嶅彧鑳介€氳繃鎸夌i涓寜閽潵鏀瑰彉銆? *   鎵€浠ユ灇涓剧涓€涓寜閽殑2绉嶇姸鎬侊紝璐績鎺ㄥ鍚庣画鍗冲彲銆傚彇鍙鏂规涓鏁板皯鐨勩€? *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

string src, dst; int n;

/*-----solve锛氭ā鎷熲€斺€旂粰瀹氱涓€涓寜閽槸鍚︽寜涓?----*/
int solve(bool pressFirst) {
    string s = src; int cnt = 0;
    if (pressFirst) {
        cnt++; s[0] ^= 1;                   // 鍙嶈浆鑷韩
        if (n > 1) s[1] ^= 1;               // 鍙嶈浆鍙充晶
    }
    for (int i = 1; i < n; i++) {
        if (s[i - 1] != dst[i - 1]) {       // 褰撳墠浣嶇疆闇€瑕佹敼鍙?            cnt++;
            s[i - 1] ^= 1;                  // 鍙嶈浆宸︿晶
            s[i] ^= 1;                      // 鍙嶈浆鑷韩
            if (i + 1 < n) s[i + 1] ^= 1;   // 鍙嶈浆鍙充晶
        }
    }
    return (s[n - 1] == dst[n - 1]) ? cnt : INT_MAX;
}

int main() {
    cin >> src >> dst; n = src.size();
    int ans = min(solve(false), solve(true));
    if (ans == INT_MAX) cout << "impossible" << endl;
    else                cout << ans << endl;
    return 0;
}