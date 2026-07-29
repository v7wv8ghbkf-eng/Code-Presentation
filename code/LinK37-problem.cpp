/*-----棰樼洰鍒嗘瀽-----
 * 鏋楀厠鐨勮泲绯曪紙浜屽垎+璐績锛夛細N涓渾鏌辫泲绯曪紙楂?1锛屽崐寰剅_i锛夛紝鍒嗙粰F+1涓汉銆? * 姣忎汉鍒嗕竴鍧楀悓鍙ｅ懗锛堝嵆鍚屼竴铔嬬硶鍒囧嚭锛夛紝鍙互鍒囦絾涓嶆嫾鍑戙€傛眰鏈€澶ф瘡浜鸿兘寰楀埌鐨勪綋绉€? *
 * 瑙ｆ硶锛氫簩鍒嗙瓟妗堬紙浣撶Н锛?+ 璐績楠岃瘉銆? *   瀵圭洰鏍囦綋绉痬id锛屾瘡涓泲绯曡兘鍒囧嚭 floor(蟺*r虏 / mid) 鍧楋紝绱姞鍒ゆ柇鏄惁鈮+1銆? *   娉ㄦ剰锛毾€*r虏 鍙兘寰堝ぇ锛岀敤double锛涗负閬垮厤绮惧害闂鐩存帴鐢╮虏姣旇緝銆? *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

const int N = 10010;
const double PI = acos(-1.0);
int n, F;
double vol[N];                              // 姣忎釜铔嬬硶鐨勪綋绉紙鍚€锛?
/*-----check锛氭瘡浜哄垎鍒颁綋绉痻鏄惁鍙兘-----*/
bool check(double x) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += (int)(vol[i] / x);           // 璇ヨ泲绯曡兘鍒囧嚭鍑犲潡
    return cnt >= F + 1;                    // 澶熶笉澶烣+1浜?}

int main() {
    cin >> n >> F;
    double L = 0, R = 0;
    for (int i = 0; i < n; i++) {
        int r; cin >> r;
        vol[i] = PI * r * r;                // 璇ヨ泲绯曚綋绉?        R = max(R, vol[i]);
    }
    // 浜屽垎娴偣鏁扮瓟妗?    for (int iter = 0; iter < 100; iter++) {
        double mid = (L + R) / 2.0;
        if (check(mid)) L = mid; else R = mid;
    }
    cout << fixed << setprecision(3) << L << endl;
    return 0;
}