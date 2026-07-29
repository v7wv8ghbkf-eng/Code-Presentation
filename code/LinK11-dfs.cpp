#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 10;

int n;

/*-----dfs函数分析-----*/
// dfs：对从1到n的n个数按照字典序输出其所有可能的排列（由题意）
// 但很显然n是固定值，这里使用它不合适，而且已经设置全局变量了
// 这里对每层，都属于一个“选不选某个数字”的问题，需要标记数字使用情况;同时也需要数组来装在、演示时用过的数字
bool st[N];
vector<int> arr;
// 只需要关心是否触底，这也是需要变动并经由dfs传递的“状态”
void dfs(int depth)
{
    // 考虑递归出口的时候，除了考虑最简单的子问题，也可以考虑循环结束/dfs操作结束的标志
    // 这样的标志往往可以或者应当通过形参在各个dfs调用中传递
    if (depth == n)
    {
        for (int x = 0; x < arr.size(); x++)
        {
            cout << arr[x];
            if (x != arr.size() - 1)
                cout << " ";
        }
        cout << endl;
        return;
    }

    // 每次都从1开始到n枚举，选择还没用过的数字放到外显数组中
    for(int x = 1; x <= n; x++)
    {
        if(!st[x])
        {
            arr.push_back(x);
            st[x] = true;
            dfs(depth + 1);
            // 一整条调用结束，恢复现场，也就是恢复st和arr状态
            st[x] = false;
            arr.pop_back();
        }
    }

    return;
}

int main()
{
    // 初始化
    memset(st, false, sizeof(st));

    cin >> n;
    dfs(0);
    return 0;
}