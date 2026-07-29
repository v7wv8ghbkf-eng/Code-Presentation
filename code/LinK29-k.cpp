/*-----棰樼洰鍒嗘瀽-----
 * 杈撳嚭鍓?k 澶х殑鏁帮細
 *   缁欏畾涓€涓暱搴︿负 n锛坣 < 100000锛夌殑鏁存暟鏁扮粍鍜屼竴涓暣鏁?k锛坘 < n锛夛紝
 *   瑕佹眰鎵惧嚭鍓?k 澶х殑鏁帮紝骞朵粠澶у埌灏忚緭鍑猴紝姣忎釜鏁板崰涓€琛屻€? *
 * 瑙ｉ鎬濊矾锛圫TL nth_element 瑙ｆ硶锛夛細
 *   鐩存帴浣跨敤 C++ STL 涓殑 nth_element锛屽叾鍐呴儴閲囩敤 Introselect 绠楁硶
 *   锛堝揩閫熼€夋嫨 + 鍫嗘帓搴忕殑娣峰悎锛夛紝淇濊瘉鏈€鍧忔儏鍐?O(n) 鐨勬椂闂村鏉傚害銆? *
 * 姝ラ锛? *   1. 鐢?nth_element 灏嗙 n-k 灏忕殑鍏冪礌鏀惧埌 nums[n-k] 浣嶇疆锛? *      鍚屾椂淇濊瘉 [n-k, n) 鍖洪棿鐨勫厓绱犳槸鍓?k 澶х殑鏁帮紙鍐呴儴鏈帓搴忥級銆? *   2. 瀵?[n-k, n) 鍖洪棿鐢?sort + greater<int>() 浠庡ぇ鍒板皬鎺掑簭銆? *   3. 渚濇杈撳嚭銆? *
 * 娉ㄦ剰锛氬師娉ㄩ噴涓繚鐣欎簡涔嬪墠閿欒灏濊瘯鐨勪唬鐮侊紙宸叉敞閲婏級锛屼粎渚涘弬鑰冦€? */
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100000;
int numbers[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    int k;
    scanf("%d", &k);

    /*-----STL nth_element 蹇€熷垝鍒?----
     * nth_element 閲嶆柊鎺掑垪鏁扮粍锛屼娇寰楋細
     *   - numbers[n-k] 澶勭殑鍏冪礌绛変簬瀹屽叏鎺掑簭鍚庤浣嶇疆鐨勫厓绱?     *   - numbers[n-k] 宸︿晶鐨勫厓绱犻兘 鈮?瀹冿紝鍙充晶鐨勫厓绱犻兘 鈮?瀹?     * 杩欐牱 [n-k, n) 鍖洪棿灏卞寘鍚簡鍓?k 澶х殑鏁帮紙浣嗗唴閮ㄦ棤搴忥級銆?     *
     * 鍐呴儴浣跨敤 Introselect锛堝揩閫熼€夋嫨 + 鍫嗘帓搴忓閫夛級锛?     * 淇濊瘉鍗充娇鍦ㄦ渶鍧忔儏鍐典笅涔熸槸 O(n)銆?     */
    nth_element(numbers, numbers + n - k, numbers + n);

    // 灏嗗墠k澶х殑鏁颁粠澶у埌灏忔帓鍒?    sort(numbers + n - k, numbers + n, greater<int>());

    // 杈撳嚭鍓峩澶х殑鏁帮紝姣忚涓€涓?    for (int i = n - k; i < n; i++) {
        printf("%d\n", numbers[i]);
    }
    return 0;
}
