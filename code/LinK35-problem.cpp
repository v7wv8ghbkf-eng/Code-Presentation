/*-----棰樼洰鍒嗘瀽-----
 * 鏁扮殑涓夋鏂规牴锛氱粰瀹氭诞鐐规暟n锛岃緭鍑簄^(1/3)锛屼繚鐣?浣嶅皬鏁般€俷鑼冨洿[-10000,10000]銆? * 瑙ｆ硶锛氫簩鍒嗭紝娉ㄦ剰澶勭悊璐熸暟銆? *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    double n; cin >> n;
    double L = min(-1.0, n), R = max(1.0, n);  // 纭繚鍖洪棿鍖呭惈绔嬫柟鏍?    for (int i = 0; i < 100; i++) {             // 鍥哄畾100娆¤凯浠ｄ繚璇佺簿搴?        double mid = (L + R) / 2.0;
        if (mid * mid * mid >= n) R = mid; else L = mid;
    }
    cout << fixed << setprecision(6) << L << endl;
    return 0;
}