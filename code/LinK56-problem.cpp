/*-----题目分析-----
 * 滚石柱（Bloxorz）：一个1×1×2的长方体石柱在N×M的迷宫中滚动。
 * 石柱有3种状态：立着(0)、横躺(1)、竖躺(2)。
 * 需要滚动到目标位置'O'上且状态为立着，求最少步数；无解输出"Impossible"。
 *
 * 解法：BFS（状态为 (x, y, st) 三元组）
 *   st=0（立）：占据1格 (x,y)，不能立在'E'上
 *   st=1（横躺）：占据2格 (x,y)和(x,y+1)
 *   st=2（竖躺）：占据2格 (x,y)和(x+1,y)
 *
 * 多组测试数据，以"0 0"结束。
 * 数据范围：3 ≤ N, M ≤ 500
 *-----题目分析-----*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 510;

int row, col;
char area[N][N];

/*-----石柱状态结构-----*/
// st=0：立着 (x,y)
// st=1：横躺，占据(x,y)和(x,y+1)
// st=2：竖躺，占据(x,y)和(x+1,y)
struct Stone {
    int x, y, st;
};
Stone src, dst;                             // 起点和终点

/*-----isInside-----*/
// 判断坐标是否在迷宫范围内
inline bool isInside(int x, int y) {
    return x >= 0 && x < row && y >= 0 && y < col;
}

/*-----isValid-----*/
// 判断石柱当前状态是否合法
// 规则：不能有任何部位在禁地'#'上；立着时不能站在易碎地'E'上
inline bool isValid(Stone s) {
    // 基本检查：主坐标必须在界内且非禁地
    if (!isInside(s.x, s.y) || area[s.x][s.y] == '#') return false;

    // 横躺：右边那格也必须在界内且非禁地
    if (s.st == 1 && (!isInside(s.x, s.y + 1) || area[s.x][s.y + 1] == '#'))
        return false;

    // 竖躺：下边那格也必须在界内且非禁地
    if (s.st == 2 && (!isInside(s.x + 1, s.y) || area[s.x + 1][s.y] == '#'))
        return false;

    // 立着时不能站在易碎地面上
    if (s.st == 0 && area[s.x][s.y] == 'E') return false;

    return true;
}

/*-----nextState：计算滚动后的状态-----*/
// 对石柱执行向(dir)方向滚动，dir: 0=右, 1=左, 2=下, 3=上
// 返回滚动后的新状态（不检查合法性，由调用者检查）
Stone nextState(Stone s, int dir) {
    Stone nxt;
    if (s.st == 0) {                        // 当前立着
        if (dir == 0)      nxt = {s.x, s.y + 1, 1};  // 向右滚 → 横躺
        else if (dir == 1) nxt = {s.x, s.y - 2, 1};  // 向左滚 → 横躺
        else if (dir == 2) nxt = {s.x + 1, s.y, 2};  // 向下滚 → 竖躺
        else               nxt = {s.x - 2, s.y, 2};  // 向上滚 → 竖躺
    } else if (s.st == 1) {                 // 当前横躺
        if (dir == 0)      nxt = {s.x, s.y + 2, 0};  // 向右滚 → 立着
        else if (dir == 1) nxt = {s.x, s.y - 1, 0};  // 向左滚 → 立着
        else if (dir == 2) nxt = {s.x + 1, s.y, 1};  // 向下滚 → 横躺
        else               nxt = {s.x - 1, s.y, 1};  // 向上滚 → 横躺
    } else {                                // 当前竖躺 (s.st == 2)
        if (dir == 0)      nxt = {s.x, s.y + 1, 2};  // 向右滚 → 竖躺
        else if (dir == 1) nxt = {s.x, s.y - 1, 2};  // 向左滚 → 竖躺
        else if (dir == 2) nxt = {s.x + 2, s.y, 0};  // 向下滚 → 立着
        else               nxt = {s.x - 1, s.y, 0};  // 向上滚 → 立着
    }
    return nxt;
}

/*-----BFS-----*/
// dist[x][y][st]：到达状态(x,y,st)的最少步数，-1表示未访问
int dist[N][N][3];

int bfs() {
    memset(dist, -1, sizeof(dist));
    queue<Stone> q;

    dist[src.x][src.y][src.st] = 0;
    q.push(src);

    while (!q.empty()) {
        Stone cur = q.front();
        q.pop();

        // 到达目标：立着站在'O'上
        if (cur.st == 0 && area[cur.x][cur.y] == 'O')
            return dist[cur.x][cur.y][cur.st];

        for (int dir = 0; dir < 4; dir++) {
            Stone nxt = nextState(cur, dir);
            if (!isValid(nxt)) continue;    // 非法状态跳过
            if (dist[nxt.x][nxt.y][nxt.st] != -1) continue;  // 已访问

            dist[nxt.x][nxt.y][nxt.st] = dist[cur.x][cur.y][cur.st] + 1;
            q.push(nxt);
        }
    }

    return -1;                              // 无解
}

/*-----build_map-----*/
// 读取地图，定位起点和终点
void build_map() {
    for (int i = 0; i < row; i++) {
        cin >> area[i];
    }

    src.st = -1;                            // 标记未找到起点
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (area[i][j] == '#') continue;

            if (area[i][j] == 'X') {
                // 起点：检查是单独一个X还是两个相邻的X
                if (src.st == -1) {
                    // 向右检查是否横躺
                    if (j + 1 < col && area[i][j + 1] == 'X') {
                        src = {i, j, 1};    // 横躺起点
                    }
                    // 向下检查是否竖躺
                    else if (i + 1 < row && area[i + 1][j] == 'X') {
                        src = {i, j, 2};    // 竖躺起点
                    }
                    else {
                        src = {i, j, 0};    // 立着起点
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> row >> col && row && col) {
        build_map();

        int ans = bfs();
        if (ans == -1)
            cout << "Impossible" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}