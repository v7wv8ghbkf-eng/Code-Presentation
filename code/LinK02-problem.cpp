/*-----题目分析-----*/
// 寻找所有四元组 (a, b, c, d)，满足 a³ = b³ + c³ + d³
// 其中 1 < a, b, c, d ≤ N (N ≤ 100)，且 b ≤ c ≤ d
// 输出格式：Cube = a, Triple = (b,c,d)
// 按 a 升序输出，a 相同时按 b → c → d 优先级输出

#include<iostream>
using namespace std;

/*-----立方函数-----*/
// 返回 x 的立方值，内联减少函数调用开销
inline int v(int x)
{
    return x * x * x;
}

int main()
{
    int N;
    cin >> N;

    // 四重循环枚举 a, b, c, d
    // b ≤ c ≤ d 的约束通过循环起点保证：b从2开始，c从b开始，d从c开始
    for (int a = 2; a <= N; a++)
    {
        for (int b = 2; b < a; b++)           // 确保严格b < a,因为立方和不可能等于更大的立方
        {
            // 确保b、c、d严格的递增关系
            for (int c = b; c < a; c++)       // c ≥ b，且 c < a
            {
                for (int d = c; d < a; d++)   // d ≥ c，且 d < a
                {
                    if (v(a) == v(b) + v(c) + v(d))
                    {
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
                    }
                }
            }
        }
    }
    return 0;
}