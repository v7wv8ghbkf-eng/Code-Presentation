/*-----题目分析-----
 * 林克的蛋糕（二分+贪心）：N个圆柱蛋糕（高=1，半径r_i），分给F+1个人。
 * 每人分一块同口味（即同一蛋糕切出），可以切但不拼凑。求最大每人能得到的体积。
 *
 * 解法：二分答案（体积） + 贪心验证。
 *   对目标体积mid，每个蛋糕能切出 floor(π*r² / mid) 块，累加判断是否≥F+1。
 *   注意：π*r² 可能很大，用double；为避免精度问题直接用r²比较。
 *-----题目分析-----*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

const int N = 10010;
const double PI = acos(-1.0);
int n, F;
double vol[N];                              // 每个蛋糕的体积（含π）

/*-----check：每人分到体积x是否可能-----*/
bool check(double x) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += (int)(vol[i] / x);           // 该蛋糕能切出几块
    return cnt >= F + 1;                    // 够不够F+1人
}

int main() {
    cin >> n >> F;
    double L = 0, R = 0;
    for (int i = 0; i < n; i++) {
        int r; cin >> r;
        vol[i] = PI * r * r;                // 该蛋糕体积
        R = max(R, vol[i]);
    }
    // 二分浮点数答案
    for (int iter = 0; iter < 100; iter++) {
        double mid = (L + R) / 2.0;
        if (check(mid)) L = mid; else R = mid;
    }
    cout << fixed << setprecision(3) << L << endl;
    return 0;
}