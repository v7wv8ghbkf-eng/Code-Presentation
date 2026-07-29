/*-----棰樼洰鍒嗘瀽-----
 * 杈撳叆涓€涓?2浣嶆暣鏁帮紙鍙负璐熸暟锛夛紝杈撳嚭鍏朵簩杩涘埗琛ㄧず涓?鐨勪釜鏁般€? * 璐熸暟鍦ㄨ绠楁満涓敤琛ョ爜琛ㄧず锛屽洜姝?-2 鐨勪簩杩涘埗鏈?1涓?銆? * 瑙ｆ硶锛氫娇鐢?lowbit 绠楁硶锛屾瘡娆″噺鍘?n & -n锛堟渶浣庝綅鐨?锛夛紝璁℃暟+1
 *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
using namespace std;

/*-----lowbit鍑芥暟-----*/
// lowbit(n) = n & -n锛岃繑鍥?n 鐨勪簩杩涘埗琛ㄧず涓渶浣庝綅鐨?鎵€浠ｈ〃鐨勫€?// 渚嬪锛歭owbit(12) = lowbit(1100鈧? = 4 (鍗?00鈧?
//       lowbit(-2) = lowbit(1111...1110鈧? = 2
int lowbit(int n) {
    return n & -n;
}

/*-----NumberOf1鍑芥暟-----*/
// 缁熻 n 鐨勪簩杩涘埗涓?鐨勪釜鏁?// 鍘熺悊锛氭瘡娆＄敤 n -= lowbit(n) 娑堝幓鏈€浣庝綅鐨?锛岃鏁?1锛岀洿鍒?n 鍙樹负 0
int NumberOf1(int n) {
    int res = 0;
    for (int i = n; i; i -= lowbit(i))
        res++;
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << NumberOf1(n) << endl;
    return 0;
}