/*-----棰樼洰鍒嗘瀽-----*/
// 浜烘湁涓変釜鐢熺悊鍛ㄦ湡锛氫綋鍔?23澶?銆佹劅鎯?28澶?銆佹櫤鍔?33澶?
// 缁欏畾姣忎釜鍛ㄦ湡涓婁竴娆￠珮宄板嚭鐜扮殑澶╂暟 p, e, i 鍜屽綋鍓嶅ぉ鏁?d
// 姹備笅涓€娆′笁涓珮宄板悓鏃跺嚭鐜扮殑澶╂暟锛堣窛 d 鐨勫ぉ鏁帮級
//
// 瑙ｆ硶锛氫腑鍥藉墿浣欏畾鐞?(Chinese Remainder Theorem)
// 姹?x 婊¤冻锛歺 鈮?p (mod 23), x 鈮?e (mod 28), x 鈮?i (mod 33)
// 妯℃暟涓や袱浜掕川锛孧 = 23 脳 28 脳 33 = 21252

#include <iostream>
using namespace std;

int main() {
    int p, e, i, d;
    int caseNo = 1;
    const int M = 21252;                // M = 23 脳 28 脳 33

    // 涓変釜鍛ㄦ湡鐨勬ā鏁?    int m1 = 23, m2 = 28, m3 = 33;

    // M_i = M / m_i锛屽垎鍒槸鍓旈櫎褰撳墠妯℃暟鍚庡叾浠栨ā鏁扮殑涔樼Н
    int M1 = 924, M2 = 759, M3 = 644;   // 924 = 28脳33, 759 = 23脳33, 644 = 23脳28

    /*-----姹傞€嗗厓 t_i-----*/
    // t_i 婊¤冻 (M_i 脳 t_i) 鈮?1 (mod m_i)
    // 鐢变簬妯℃暟寰堝皬锛岀洿鎺ユ灇涓?1 鍒?m_i-1 鍗冲彲
    int t1 = 0, t2 = 0, t3 = 0;
    for (int k = 1; k < m1; k++) if ((M1 * k) % m1 == 1) { t1 = k; break; }
    for (int k = 1; k < m2; k++) if ((M2 * k) % m2 == 1) { t2 = k; break; }
    for (int k = 1; k < m3; k++) if ((M3 * k) % m3 == 1) { t3 = k; break; }

    // 澶氱粍杈撳叆锛屼互 -1 -1 -1 -1 缁撴潫
    while (cin >> p >> e >> i >> d) {
        if (p == -1 && e == -1 && i == -1 && d == -1) break;

        /*-----涓浗鍓╀綑瀹氱悊鍏紡-----*/
        // x = 危(p_i 脳 M_i 脳 t_i) mod M
        int x = (p * M1 * t1 + e * M2 * t2 + i * M3 * t3) % M;

        // 闇€瑕佺殑鏄笅涓€娆￠珮宄帮紙鍗充弗鏍煎湪 d 涔嬪悗锛夛紝濡傛灉 x 鈮?d 鍒欏姞涓婂懆鏈?M
        if (x <= d) x += M;

        cout << "Case " << caseNo++ << ": the next triple peak occurs in "
             << (x - d) << " days." << endl;
    }

    return 0;
}