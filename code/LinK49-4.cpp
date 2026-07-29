/*-----题目分析-----
 * 16×16字母数独：填入A~P使每行每列每个4×4宫格内16个字母各出现一次。
 * 输入中'-'表示空格，多组数据以空行分隔，输入至EOF。
 *
 * 解法：DFS + 二进制状态压缩（类LinK47但扩展到16×16）。
 *   row/col/cell用16位二进制表示可用字母，lowbit取交集。
 *   优化搜索顺序：每次选可选字母最少的空格。
 *-----题目分析-----*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 16, M = 1 << N;               // M=65536
int row[N], col[N], cell[4][4];             // 二进制状态
int ones[M], map[M];                        // 打表
char str[N][N + 1];                         // 棋盘（含'\0'）

inline int lowbit(int x) { return x & -x; }
inline int get(int x, int y) { return row[x] & col[y] & cell[x/4][y/4]; }

void init() {
    for (int i = 0; i < N; i++) map[1 << i] = i;
    for (int i = 0; i < M; i++) {
        ones[i] = 0;
        for (int j = i; j; j -= lowbit(j)) ones[i]++;
    }
    for (int i = 0; i < N; i++) row[i] = col[i] = M - 1;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) cell[i][j] = M - 1;
}

/*-----dfs：还剩cnt个空格待填，每次选可选字母最少的格子-----*/
bool dfs(int cnt) {
    if (!cnt) return true;                  // 全部填完
    int minv = 17, x = 0, y = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (str[i][j] == '-' && ones[get(i, j)] < minv)
                minv = ones[get(i, j)], x = i, y = j;

    for (int i = get(x, y); i; i -= lowbit(i)) {
        int t = map[lowbit(i)];
        row[x] -= 1 << t; col[y] -= 1 << t; cell[x/4][y/4] -= 1 << t;
        str[x][y] = 'A' + t;
        if (dfs(cnt - 1)) return true;
        row[x] += 1 << t; col[y] += 1 << t; cell[x/4][y/4] += 1 << t;
        str[x][y] = '-';
    }
    return false;
}

int main() {
    bool first = true;
    while (cin >> str[0]) {
        for (int i = 1; i < N; i++) cin >> str[i];
        init(); int cnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (str[i][j] != '-') {
                    int t = str[i][j] - 'A';
                    row[i] -= 1 << t; col[j] -= 1 << t; cell[i/4][j/4] -= 1 << t;
                } else cnt++;
        dfs(cnt);
        if (!first) cout << endl; first = false;
        for (int i = 0; i < N; i++) cout << str[i] << endl;
    }
    return 0;
}