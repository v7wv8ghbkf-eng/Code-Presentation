/*-----题目分析-----
 * 最小预算值（二分+贪心）：N天开销分为M组（每组连续），每组预算固定。
 * 求能满足所有组的最小预算值。
 *
 * 解法：二分答案 + 贪心验证。
 *   二分预算值budget，贪心从左到右分组：若当前组加入下一天不超过budget则加入，
 *   否则新开一组。最终分组数≤M则可行。
 *-----题目分析-----*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int n, m, a[N];

/*-----check：验证预算值x是否可行-----*/
// 将N天按预算x分组，统计组数，若≤M则可行
bool check(int x) {
    int cnt = 1, sum = 0;                   // cnt:组数, sum:当前组总和
    for (int i = 0; i < n; i++) {
        if (a[i] > x) return false;         // 某一天本身超过预算，不可行
        if (sum + a[i] <= x) {
            sum += a[i];                    // 加入当前组
        } else {
            cnt++;                          // 新开一组
            sum = a[i];
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
        L = max(L, a[i]);                   // 下界：最大单日开销
        R += a[i];                          // 上界：全部总和
    }
    while (L < R) {
        int mid = (L + R) >> 1;
        if (check(mid)) R = mid; else L = mid + 1;
    }
    cout << L << endl;
    return 0;
}