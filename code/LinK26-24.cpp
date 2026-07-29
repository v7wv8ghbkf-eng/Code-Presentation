/*-----题目分析-----
 * 算24：给4个<10的非负整数，用+ - * /和括号能否凑出24。多组数据，以4个0结束。
 * 数字可重排，除法按实数除。
 *
 * 解法：DFS枚举所有运算过程。从n个数中选2个做6种运算(a+b,a-b,b-a,a*b,a/b,b/a)，
 *       结果与剩余数组成新数组（规模-1），递归到只剩1个数判断是否为24。
 *-----题目分析-----*/
#include <iostream>
#include <cmath>
using namespace std;
const double EPS = 1e-6;

bool dfs(double a[], int n) {
    if (n == 1) return fabs(a[0] - 24.0) < EPS;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            double b[4]; int m = 0;
            for (int k = 0; k < n; k++)
                if (k != i && k != j) b[m++] = a[k];  // 剩余数放入b

            b[m] = a[i] + a[j]; if (dfs(b, m + 1)) return true;  // +
            b[m] = a[i] - a[j]; if (dfs(b, m + 1)) return true;  // a-b
            b[m] = a[i] * a[j]; if (dfs(b, m + 1)) return true;  // *
            if (fabs(a[j]) > EPS) { b[m] = a[i] / a[j]; if (dfs(b, m + 1)) return true; }  // a/b
        }
    }
    return false;
}

int main() {
    double a[4];
    while (cin >> a[0] >> a[1] >> a[2] >> a[3]) {
        if (a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0) break;
        cout << (dfs(a, 4) ? "YES" : "NO") << endl;
    }
    return 0;
}