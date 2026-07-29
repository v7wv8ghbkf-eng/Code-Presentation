/*-----题目分析-----
 * Dijkstra求最短路（堆优化版 O(m log n)）：
 * 给定一个n个点m条边的有向图，所有边权均为正值。
 * 求从1号点到n号点的最短距离，若不可达则输出-1。
 *
 * 解法：堆优化Dijkstra，适用于稀疏图（边数m远小于n²）
 *   用优先队列（小根堆）维护(dist, node)，每次取出堆顶的未确定点，
 *   标记为已确定，并松弛其所有出边。
 * 时间复杂度 O(m log n)
 *-----题目分析-----*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> PII;                 // (距离, 节点编号)

const int N = 150010;                       // 边数上限
const int INF = 0x3f3f3f3f;

int n, m;

/*-----邻接表-----*/
// h[i]：以i为起点的第一条边的索引
// e[idx]：第idx条边的终点；w[idx]：边权；ne[idx]：下一条边的索引
int h[N], e[N], ne[N], w[N], idx;

int dist[N];                                // dist[i]：1到i的最短距离
bool st[N];                                 // st[i]：i的最短距离是否已确定

/*-----add：添加一条有向边 a→b，权值为c-----*/
void add(int a, int b, int c) {
    e[idx] = b;                             // 边的终点
    w[idx] = c;                             // 边权
    ne[idx] = h[a];                         // 链表头插法：新边指向原链表头
    h[a] = idx++;                           // 更新链表头
}

/*-----dijkstra函数分析-----*/
// 堆优化Dijkstra：用优先队列自动维护当前dist最小的节点
int dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    memset(st, false, sizeof(st));
    dist[1] = 0;

    // 小根堆：按距离从小到大排列
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});                      // (距离, 节点编号)

    while (!heap.empty()) {
        auto top = heap.top(); int d = top.first, t = top.second; // d是1到t的当前最短距离
        heap.pop();

        if (st[t]) continue;                // 已确定，跳过（堆中可能有过期数据）
        st[t] = true;                       // 标记t的最短距离已确定

        /*-----松弛t的所有出边-----*/
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];                   // 邻接点
            // 如果通过t到达j比当前dist[j]更短，则更新并入堆
            if (dist[j] > d + w[i]) {
                dist[j] = d + w[i];
                heap.push({dist[j], j});    // 注意：可能有重复节点，由st[t]检查去重
            }
        }
    }

    if (dist[n] == INF) return -1;          // 不可达
    return dist[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h, -1, sizeof(h));               // 邻接表头初始化为-1（空链表）
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);                       // 邻接表自动处理重边（多条边共存）
    }

    cout << dijkstra() << endl;
    return 0;
}