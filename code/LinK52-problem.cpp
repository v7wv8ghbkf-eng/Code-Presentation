/*-----题目分析-----
 * 机器人可达范围（BFS + 数位和约束）：
 * 在m×n的网格中，从(0,0)出发，每次向上下左右移动一格，
 * 但不能进入行坐标和列坐标的数位之和大于k的格子。
 * 求能到达多少个格子。
 *
 * 数位和：例如(35,37)，3+5+3+7=18，若k≥18则可进入，否则不能。
 * 约束：0≤k≤100，0≤m≤50，0≤n≤50
 *-----题目分析-----*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 110;

typedef pair<int, int> PII;
int m, n;                               // m行n列
bool st[N][N];                          // 访问标记（每个BFS只用一次，不需重置）

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

/*-----get_plus函数-----*/
// 计算整数x的各数位之和（例如18→1+8=9）
inline int get_plus(int x)
{
    int res = 0;
    while (x)
    {
        res += x % 10;                  // 取个位
        x /= 10;                        // 去掉个位
    }
    return res;
}

/*-----bfs函数分析-----*/
// BFS从(sx,sy)出发，探索所有满足"数位和≤k"的格子
// 由于约束是数位和阈值，合法区域是连通的（从原点开始），BFS不会漏掉
int bfs(int sx, int sy, int k)
{
    memset(st, false, sizeof(st));      // 每次BFS重新初始化访问标记
    queue<PII> q;
    int res = 0;
    q.push({sx, sy});
    st[sx][sy] = true;

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        res++;                          // 计数可达格子

        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];

            if (x < 0 || x >= m || y < 0 || y >= n)
                continue;               // 越界
            // 数位和超过k 或 已访问，跳过
            if (get_plus(x) + get_plus(y) > k || st[x][y])
                continue;

            q.push({x, y});
            st[x][y] = true;
        }
    }

    return res;
}

int main()
{
    int k;
    cin >> k >> m >> n;

    cout << bfs(0, 0, k) << endl;
    return 0;
}