/*-----题目分析-----
 * 字符全排列：给定一个由不同小写字母组成的字符串，输出该字符串的所有全排列。
 * 输入：一行，由不同小写字母组成的字符串（长度2~8）
 * 输出：所有排列方式，每行一个，按字母序升序输出
 * 关键点：需要先对输入字符串排序，保证DFS枚举时按字典序生成排列
 *-----题目分析-----*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 10;

// 输入字符串（排序后）
string str;
// used[i]：str[i]是否已被选入当前排列（就是之前的st[]）
bool used[N];
// 当前排列路径，外显数组
vector<char> path;

/*-----dfs函数分析-----*/
// dfs：按字典序遍历字符串的所有排列
// 递归策略：每层从未使用的字符中按顺序选取一个，加入路径并标记已用
// 递归出口：当路径长度等于字符串长度时，输出当前排列
void dfs(int depth)
{
    // 递归出口：已选出完整排列，输出
    if (depth == (int)str.size())
    {
        for (int i = 0; i < (int)path.size(); i++)
        {
            cout << path[i];
        }
        cout << endl;
        return;
    }

    // 横向枚举：按顺序尝试每个未使用的字符（因为str已排序，保证了字典序）
    for (int i = 0; i < (int)str.size(); i++)
    {
        if (!used[i])
        {
            used[i] = true;
            path.push_back(str[i]);
            dfs(depth + 1);  // 竖向深入下一层
            path.pop_back(); // 回溯：撤销选择
            used[i] = false; // 回溯：恢复标记
        }
    }
}

int main()
{
    cin >> str;

    // 对字符串排序，保证输出按字典序
    sort(str.begin(), str.end());

    memset(used, false, sizeof(used));
    dfs(0);
    return 0;
}