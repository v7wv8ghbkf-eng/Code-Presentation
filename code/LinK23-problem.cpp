/*-----题目分析-----
 * 二进制密码锁：n个按钮(n<30)，0=凹，1=凸。按一个按钮会反转自身及相邻按钮。
 * 给定初始和目标状态，求最少按按钮次数；无解输出"impossible"。
 *
 * 解法：枚举+贪心。第一个按钮按/不按决定了整个序列的后续操作——
 *   当从左到右处理到第i位时，第i-1位只能通过按第i个按钮来改变。
 *   所以枚举第一个按钮的2种状态，贪心推导后续即可。取可行方案中步数少的。
 *-----题目分析-----*/
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

string src, dst; int n;

/*-----solve：模拟——给定第一个按钮是否按下-----*/
int solve(bool pressFirst) {
    string s = src; int cnt = 0;
    if (pressFirst) {
        cnt++; s[0] ^= 1;                   // 反转自身
        if (n > 1) s[1] ^= 1;               // 反转右侧
    }
    for (int i = 1; i < n; i++) {
        if (s[i - 1] != dst[i - 1]) {       // 当前位置需要改变
            cnt++;
            s[i - 1] ^= 1;                  // 反转左侧
            s[i] ^= 1;                      // 反转自身
            if (i + 1 < n) s[i + 1] ^= 1;   // 反转右侧
        }
    }
    return (s[n - 1] == dst[n - 1]) ? cnt : INT_MAX;
}

int main() {
    cin >> src >> dst; n = src.size();
    int ans = min(solve(false), solve(true));
    if (ans == INT_MAX) cout << "impossible" << endl;
    else                cout << ans << endl;
    return 0;
}