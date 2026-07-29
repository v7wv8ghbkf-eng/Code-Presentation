/*-----题目分析-----
 * 二分法求方程根：f(x) = x³ - 5x² + 10x - 80 = 0，精确到9位小数。
 * f(0)=-80<0, f(100)>0 → 根在[0,100]区间。直接二分。
 *-----题目分析-----*/
#include <iostream>
#include <iomanip>
using namespace std;

double f(double x) { return x*x*x - 5*x*x + 10*x - 80; }

int main() {
    double L = 0.0, R = 100.0;
    while (R - L > 1e-11) {         // 二分到足够精度
        double mid = (L + R) / 2.0;
        if (f(mid) > 0) R = mid; else L = mid;
    }
    cout << fixed << setprecision(9) << L << endl;
    return 0;
}