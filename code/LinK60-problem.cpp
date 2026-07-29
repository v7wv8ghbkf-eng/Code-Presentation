/*-----题目分析-----
 * 拓扑排序：n个点m条边有向图，输出任一拓扑序列；若无（存在环）输出-1。
 *
 * 解法：BFS Kahn算法。统计每个点的入度indeg，
 *   将入度为0的点入队，逐一取出并删除其出边（邻接点入度-1），
 *   新入度变为0的点入队。若最终输出点数<n则存在环。
 *-----题目分析-----*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;                 // 邻接表
int indeg[N];                               // indeg[i]：点i的入度
vector<int> topo;                           // 拓扑序列

void add(int a, int b) {
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

bool kahn() {
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0) q.push(i);       // 入度为0的点入队

    while (!q.empty()) {
        int t = q.front(); q.pop();
        topo.push_back(t);
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (--indeg[j] == 0) q.push(j); // 删边后入度变0则入队
        }
    }
    return (int)topo.size() == n;           // 是否所有点都入了拓扑序
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        add(a, b); indeg[b]++;
    }
    if (kahn()) {
        for (int i = 0; i < n; i++)
            cout << topo[i] << (i == n-1 ? "\n" : " ");
    } else {
        cout << -1 << endl;
    }
    return 0;
}