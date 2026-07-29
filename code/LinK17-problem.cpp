/*-----题目分析-----
 * 波兰表达式（前缀表达式）求值：
 * 运算符写在操作数之前，如 "* + 2 3 4" 表示 (2+3)*4=20。
 * 输入为空格分隔的前缀表达式，操作数为浮点数。
 *
 * 解法：递归。前缀表达式天然适合递归：
 *   读入一个token → 是运算符则递归求左右操作数并运算；
 *   是数字则直接转double返回。
 *-----题目分析-----*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/*-----dfs：递归求值-----*/
double dfs() {
    string token; cin >> token;
    if (token == "+")      return dfs() + dfs();
    else if (token == "-") return dfs() - dfs();
    else if (token == "*") return dfs() * dfs();
    else if (token == "/") return dfs() / dfs();
    else                   return atof(token.c_str());  // 数字
}

int main() {
    printf("%f\n", dfs());
    return 0;
}