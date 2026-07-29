/*-----题目分析-----
 * 八皇后第n个解：8×8棋盘上放置8个皇后使其互不攻击，共有92组解。
 * 每组解用8位数字串表示（第i位=第i行皇后所在列号）。
 * 输入T组数据，每组n(1≤n≤92)，输出按字典序第n小的皇后串。
 *
 * 解法：DFS回溯生成所有92解（按列号1→8枚举自然保证字典序），
 *       存入数组，O(1)查询输出。
 *-----题目分析-----*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int col[9];                                 // col[row]：第row行皇后所在列（1~8）
bool used[9];                               // used[c]：第c列是否被占用
vector<int> solutions;                      // 所有92个解（整数形式，天然字典序）

/*-----check：检查(row, c)是否与已放置皇后冲突-----*/
bool check(int row, int c) {
    for (int i = 1; i < row; i++)
        if (abs(row - i) == abs(c - col[i]))
            return false;                   // 对角线冲突：行差==列差
    return true;
}

/*-----dfs：逐行放置皇后，生成全部解-----*/
void dfs(int row) {
    if (row > 8) {                          // 8行放置完毕，记录这一组解
        int num = 0;
        for (int i = 1; i <= 8; i++)
            num = num * 10 + col[i];        // 拼接为8位整数
        solutions.push_back(num);
        return;
    }
    for (int c = 1; c <= 8; c++) {          // 1→8枚举保证字典序
        if (!used[c] && check(row, c)) {
            used[c] = true; col[row] = c;
            dfs(row + 1);
            used[c] = false;                // 回溯
        }
    }
}

int main() {
    dfs(1);                                 // 预生成全部92解

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << solutions[n - 1] << endl;   // 下标0对应第1个解
    }
    return 0;
}