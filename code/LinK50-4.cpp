/*-----题目分析-----
 * 16×16字母数独（同LinK49）。
 * LinK50是LinK49的副本，完全相同的题目和代码。
 *-----题目分析-----*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 16, M = 1 << N;
int row[N], col[N], cell[4][4];
int ones[M], map[M];
char str[N][N + 1];

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

bool dfs(int cnt) {
    if (!cnt) return true;
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