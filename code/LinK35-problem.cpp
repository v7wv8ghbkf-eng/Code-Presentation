/*-----题目分析-----
 * 数的三次方根：给定浮点数n，输出n^(1/3)，保留6位小数。n范围[-10000,10000]。
 * 解法：二分，注意处理负数。
 *-----题目分析-----*/
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    double n; cin >> n;
    double L = min(-1.0, n), R = max(1.0, n);  // 确保区间包含立方根
    for (int i = 0; i < 100; i++) {             // 固定100次迭代保证精度
        double mid = (L + R) / 2.0;
        if (mid * mid * mid >= n) R = mid; else L = mid;
    }
    cout << fixed << setprecision(6) << L << endl;
    return 0;
}