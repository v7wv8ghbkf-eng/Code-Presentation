/*-----题目分析-----
 * N皇后问题（棋盘格式输出）：在N×N的棋盘上放置N个皇后，使其互不攻击。
 * 输入：n（1<=n<=12）
 * 输出：每个方案占n行，每行输出一个长度为n的字符串，
 *       '.' 表示空格，'Q' 表示皇后；每个方案后输出一个空行
 * 思路：与LinK13类似，但需要构建棋盘并用对角线数组优化冲突判断
 *       对角线索引：主对角线用 row+c，副对角线用 row-c+n（避免负索引）
 *-----题目分析-----*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<string> board;                              // 棋盘状态
bool col[15], diag1[30], diag2[30];                // 列、主对角线、副对角线占用标记
// diag1[row+c]：主对角线（从左上到右下），同一主对角线上 row+c 为定值
// diag2[row-c+n]：副对角线（从右上到左下），+n 偏移避免负索引

/*-----dfs函数分析-----*/
// dfs：逐行放置皇后，row表示当前行（0-indexed）
// 递归出口：row == n 表示所有行都已放置完毕，输出棋盘
// 递归策略：枚举当前行的每一列，检查列和两条对角线是否被占用
void dfs(int row) {
    if (row == n) {
        // 输出当前棋盘方案
        for (int i = 0; i < n; i++) {
            cout << board[i] << endl;
        }
        cout << endl;       // 每个方案后输出空行
        return;
    }
    // 横向枚举：尝试当前行的每一列
    for (int c = 0; c < n; c++) {
        // 同时检查列、主对角线、副对角线是否被占用
        if (!col[c] && !diag1[row + c] && !diag2[row - c + n]) {
            // 放置皇后，标记占用
            col[c] = diag1[row + c] = diag2[row - c + n] = true;
            board[row][c] = 'Q';
            dfs(row + 1);       // 递归下一行
            // 回溯：撤销占用标记和棋盘状态
            board[row][c] = '.';
            col[c] = diag1[row + c] = diag2[row - c + n] = false;
        }
    }
}

int main() {
    cin >> n;
    // 初始化棋盘为全'.'
    board.resize(n, string(n, '.'));
    dfs(0);     // 从第0行开始放置
    return 0;
}