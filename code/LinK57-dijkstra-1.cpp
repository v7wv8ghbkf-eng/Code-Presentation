/*-----题目分析-----
 * Dijkstra求最短路（朴素版 O(n²)）：
 * 给定一个n个点m条边的有向图，可能存在重边和自环，所有边权均为正值。
 * 求从1号点到n号点的最短距离，若不可达则输出-1。
 *
 * 解法：朴素Dijkstra算法，适用于稠密图（边数m接近n²）
 *   每次从未确定最短距离的点中找出dist最小的点t，
 *   将其标记为已确定，并用t更新所有邻接点的dist。
 * 时间复杂度 O(n²)
 *-----题目分析-----*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 510;

int n, m;
int w[N][N];                                // 邻接矩阵，w[a][b]=a到b的边权
int dist[N];                                // dist[i]：1号点到i号点的最短距离
bool st[N];                                 // st[i]：i号点的最短距离是否已确定

/*-----dijkstra函数分析-----*/
// 朴素Dijkstra：每次选dist最小的未确定点，用其更新邻居
int dijkstra()
{
    memset(st, false, sizeof(st));
    memset(dist, 0x3f, sizeof(dist));       // 0x3f3f3f3f ≈ 1e9，一个"大而不溢出"的值

    dist[1] = 0;                            // 起点距离为0

    /*-----迭代 n-1 次-----*/
    // 每次确定一个点的最短距离（最后一个点不需要更新别人，所以n-1次即可）
    for (int i = 0; i < n - 1; i++)
    {
        /*-----第一步：从所有未确定点中找到dist最小的点t-----*/
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            // 如果点j未确定 且 (t==-1首次 或 dist[j] < dist[t])
            if (st[j] == false && (t == -1 || dist[t] > dist[j]))
            {
                t = j;
            }
        }

        if (t == -1) break;                 // 所有可达点都已确定（剩余不可达）
        st[t] = true;                       // 标记t的最短距离已确定

        /*-----第二步：用t更新所有邻接点的dist-----*/
        for (int j = 1; j <= n; j++)
        {
            // 若j未确定 且 通过t到达j比当前dist[j]更短，则更新
            if (!st[j] && dist[t] + w[t][j] < dist[j])
            {
                dist[j] = dist[t] + w[t][j];
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;   // 不可达
    return dist[n];
}

int main()
{
    memset(w, 0x3f, sizeof(w));             // 邻接矩阵初始化为"无穷大"

    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        w[a][b] = min(w[a][b], c);          // 处理重边：保留最短的那条
    }
    for (int i = 1; i <= n; i++)
    {
        w[i][i] = 0;                        // 自己到自己的距离为0
    }

    cout << dijkstra() << endl;
    return 0;
}