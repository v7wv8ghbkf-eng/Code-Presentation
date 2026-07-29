/*-----题目分析-----
 * 算术表达式求值：给定仅含正整数(1-9)、'*'和'+'的表达式，计算结果对1e9+7取模。
 * 输入：第一行N（数字个数，2≤N≤200000），第二行表达式字符串（2N-1个字符）
 * 输出：运算结果 mod 1000000007
 *
 * 解法：一次遍历，利用"先乘后加"的运算优先级
 *   遇到 * → 当前乘法段继续累积；遇到 + → 将当前乘法段的结果累加到答案，重置乘法段
 *   时间复杂度 O(N)，空间复杂度 O(1)
 *-----题目分析-----*/
#include <iostream>
#include <string>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string expr;
    cin >> n >> expr;

    /*-----一次遍历求值-----*/
    // 关键：表达式由数字和运算符交替组成，格式为 d1 op1 d2 op2 d3 ...
    // 乘法的优先级高于加法，所以遇到乘法就累积乘法段，遇到加法就结算乘法段
    long long ans = 0;                      // 最终结果（所有加法项的和）
    long long cur = 0;                      // 当前乘法段的值
    int num = expr[0] - '0';                // 第一个数字
    cur = num;

    // 表达式结构：num0 op1 num1 op2 num2 ...
    // i 从 1 开始，每次跳 2（跳过运算符+数字）：i 指向运算符，i+1 指向下一个数字
    for (int i = 1; i < (int)expr.size(); i += 2) {
        char op = expr[i];                  // 运算符：'*' 或 '+'
        int nextNum = expr[i + 1] - '0';    // 下一个数字

        if (op == '*')
        {
            // 乘法：继续累积当前乘法段（因为乘法优先级高，先不结算）
            cur = (cur * nextNum) % MOD;
        } 
        else 
        {   // op == '+'
            // 加法：结算当前乘法段，将其结果加到答案中
            // 并开始新的乘法段
            ans = (ans + cur) % MOD;
            cur = nextNum;
        }
    }
    // 结算最后一个乘法段
    ans = (ans + cur) % MOD;

    cout << ans << endl;
    return 0;
}