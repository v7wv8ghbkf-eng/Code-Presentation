/*-----题目分析-----*/
// 输入N个皇后，任意两个皇后不能在同一行、列、对角线
// 棋盘大小等于N * N
// 要求输出不同的摆法，输出顺序代表从1-n每个皇后所在列序号
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int N = 15;

// 皇后个数，全局变量方便函数调用
int n;

/*-----dfs函数分析-----*/
// dfs：输出各种皇后摆放的解，这一点上和字符/数字全排列是极相似的；
// 保持这个思路，实际上皇后的摆放就等价于数字/字符的放置
// 所以递归形参也是depth，在这里就是row（行序数），表示从第row行开始
// 同样的，需要外显数组；arr[0~n-1]表示第1~n行皇后分别所在的列序号&&需要当前行列对角线的状态来判断能不能放这个皇后
vector<int> arr;
bool used[N];
// bool数组只能保证对每个行，不同列是否能放
// 所以还需要检查对角线的方式，需要分别存放各个行皇后的行列之和、之差;也需要外置检查函数
int diag1[N], diag2[N];
inline bool isValid(int row, int col)
{
    int add = row + col;
    int minus = row - col;

    for (int i = 1; i <= n; i++)
    {
        if (used[i] && (diag1[i] == add || diag2[i] == minus))
        {
            return false;
        }
    }

    return true;
}
void dfs(int row)
{
    if (row == n + 1)
    {
        for (int x = 0; x < arr.size(); x++)
        {
            cout << arr[x];
        }
        cout << endl;
        return;
    }

    for (int col = 1; col <= n; col++)
    {
        if (!used[col] && isValid(row, col))
        {
            arr.push_back(col);
            used[col] = true;
            diag1[col] = row + col;
            diag2[col] = row - col;
            dfs(row + 1);
            arr.pop_back();
            used[col] = false;
            diag1[col] = -1;
            diag2[col] = -1;
        }
    }
}

int main()
{
    memset(used, false, sizeof used);
    memset(diag1, -1, sizeof diag1);
    memset(diag2, -1, sizeof diag2);

    cin >> n;
    dfs(1);
    return 0;
}