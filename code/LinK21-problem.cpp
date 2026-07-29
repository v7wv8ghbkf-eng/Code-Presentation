/*-----与Link11重复，不做注释-----*/
// 以下注释和所标记的代码为反复遇到部分通过无法解决时，Claude Code编辑的
/*
 * 部分通过原因分析：
 * 1. cout << endl 每次都刷新缓冲区，n 较大时输出量巨大(n! 行)，导致 TLE
 *    修复：换用 '\n'，只在最后可能需要的 flush 处用 endl 或等程序结束自动 flush
 * 2. 未关闭 C/C++ IO 同步，cin/cout 效率低
 *    修复：添加 ios::sync_with_stdio(false); cin.tie(nullptr);
 * 3. <cstring> 中的 memset 在严格 C++ 标准下只保证 std::memset 存在
 *    修复：显式使用 std::memset（或直接用 vector<bool> 自动初始化为 false）
 * 4. dfs 末尾多余的 return; 已移除（void 函数自然返回即可）
 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<int> path;
bool st[30];

void dfs(int depth)
{
    if (depth == n)
    {
        for (int x = 0; x < n; x++)  // path.size() 在此处等价于 n，直接用 n 略快
        {
            cout << path[x];
            if (x != n - 1)
            {
                cout << ' ';  // 单字符用 '' 而非 "" 略快
            }
        }
        cout << '\n';  // 关键修复：用 '\n' 替代 endl，避免每行 flush
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            path.push_back(i);
            st[i] = true;
            dfs(depth + 1);
            st[i] = false;
            path.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);  // 关闭 C/C++ IO 同步，大幅提升 cin/cout 速度
    cin.tie(nullptr);             // 解除 cin 与 cout 的绑定
    cin >> n;
    std::memset(st, false, sizeof st);  // 显式使用 std::memset
    dfs(0);
    return 0;
}