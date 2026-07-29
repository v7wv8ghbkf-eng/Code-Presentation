/*-----题目分析-----
 * 输入一个32位整数（可为负数），输出其二进制表示中1的个数。
 * 负数在计算机中用补码表示，因此 -2 的二进制有31个1。
 * 解法：使用 lowbit 算法，每次减去 n & -n（最低位的1），计数+1
 *-----题目分析-----*/
#include <iostream>
using namespace std;

/*-----lowbit函数-----*/
// lowbit(n) = n & -n，返回 n 的二进制表示中最低位的1所代表的值
// 例如：lowbit(12) = lowbit(1100₂) = 4 (即100₂)
//       lowbit(-2) = lowbit(1111...1110₂) = 2
int lowbit(int n) {
    return n & -n;
}

/*-----NumberOf1函数-----*/
// 统计 n 的二进制中1的个数
// 原理：每次用 n -= lowbit(n) 消去最低位的1，计数+1，直到 n 变为 0
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