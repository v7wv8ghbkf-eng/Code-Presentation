/*-----棰樼洰鍒嗘瀽-----
 * 鏈€灏忛绠楀€硷紙浜屽垎+璐績锛夛細N澶╁紑閿€鍒嗕负M缁勶紙姣忕粍杩炵画锛夛紝姣忕粍棰勭畻鍥哄畾銆? * 姹傝兘婊¤冻鎵€鏈夌粍鐨勬渶灏忛绠楀€笺€? *
 * 瑙ｆ硶锛氫簩鍒嗙瓟妗?+ 璐績楠岃瘉銆? *   浜屽垎棰勭畻鍊糱udget锛岃椽蹇冧粠宸﹀埌鍙冲垎缁勶細鑻ュ綋鍓嶇粍鍔犲叆涓嬩竴澶╀笉瓒呰繃budget鍒欏姞鍏ワ紝
 *   鍚﹀垯鏂板紑涓€缁勩€傛渶缁堝垎缁勬暟鈮鍒欏彲琛屻€? *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int n, m, a[N];

/*-----check锛氶獙璇侀绠楀€紉鏄惁鍙-----*/
// 灏哊澶╂寜棰勭畻x鍒嗙粍锛岀粺璁＄粍鏁帮紝鑻モ墹M鍒欏彲琛?bool check(int x) {
    int cnt = 1, sum = 0;                   // cnt:缁勬暟, sum:褰撳墠缁勬€诲拰
    for (int i = 0; i < n; i++) {
        if (a[i] > x) return false;         // 鏌愪竴澶╂湰韬秴杩囬绠楋紝涓嶅彲琛?        if (sum + a[i] <= x) {
            sum += a[i];                    // 鍔犲叆褰撳墠缁?        } else {
            cnt++;                          // 鏂板紑涓€缁?            sum = a[i];
        }
    }
    return cnt <= m;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    int L = 0, R = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        L = max(L, a[i]);                   // 涓嬬晫锛氭渶澶у崟鏃ュ紑閿€
        R += a[i];                          // 涓婄晫锛氬叏閮ㄦ€诲拰
    }
    while (L < R) {
        int mid = (L + R) >> 1;
        if (check(mid)) R = mid; else L = mid + 1;
    }
    cout << L << endl;
    return 0;
}