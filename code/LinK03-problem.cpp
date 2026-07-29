/*-----题目分析-----*/
// 人有三个生理周期：体力(23天)、感情(28天)、智力(33天)
// 给定每个周期上一次高峰出现的天数 p, e, i 和当前天数 d
// 求下一次三个高峰同时出现的天数（距 d 的天数）
//
// 解法：中国剩余定理 (Chinese Remainder Theorem)
// 求 x 满足：x ≡ p (mod 23), x ≡ e (mod 28), x ≡ i (mod 33)
// 模数两两互质，M = 23 × 28 × 33 = 21252

#include <iostream>
using namespace std;

int main() {
    int p, e, i, d;
    int caseNo = 1;
    const int M = 21252;                // M = 23 × 28 × 33

    // 三个周期的模数
    int m1 = 23, m2 = 28, m3 = 33;

    // M_i = M / m_i，分别是剔除当前模数后其他模数的乘积
    int M1 = 924, M2 = 759, M3 = 644;   // 924 = 28×33, 759 = 23×33, 644 = 23×28

    /*-----求逆元 t_i-----*/
    // t_i 满足 (M_i × t_i) ≡ 1 (mod m_i)
    // 由于模数很小，直接枚举 1 到 m_i-1 即可
    int t1 = 0, t2 = 0, t3 = 0;
    for (int k = 1; k < m1; k++) if ((M1 * k) % m1 == 1) { t1 = k; break; }
    for (int k = 1; k < m2; k++) if ((M2 * k) % m2 == 1) { t2 = k; break; }
    for (int k = 1; k < m3; k++) if ((M3 * k) % m3 == 1) { t3 = k; break; }

    // 多组输入，以 -1 -1 -1 -1 结束
    while (cin >> p >> e >> i >> d) {
        if (p == -1 && e == -1 && i == -1 && d == -1) break;

        /*-----中国剩余定理公式-----*/
        // x = Σ(p_i × M_i × t_i) mod M
        int x = (p * M1 * t1 + e * M2 * t2 + i * M3 * t3) % M;

        // 需要的是下一次高峰（即严格在 d 之后），如果 x ≤ d 则加上周期 M
        if (x <= d) x += M;

        cout << "Case " << caseNo++ << ": the next triple peak occurs in "
             << (x - d) << " days." << endl;
    }

    return 0;
}