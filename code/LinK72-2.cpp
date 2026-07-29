#include <iostream>
#include <algorithm>
using namespace std;

// 确认大致的数组范围，防止数组太小、边界太紧从而发生越界
const int N = 1010;

// 序列长度
int n;
/*-----状态表示f[i]-----*/
// 【集合】以第i个数结尾的所有上升子序列中，最长的那一个的长度
int f[N];
// a[i]原序列的第i个数值
int a[N];

int main()
{
    // 输入序列长度和元素，下标从0开始
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    /*----- 状态递推：O(N²)-----*/
    // res存储最终答案（全局最长长度）
    // 注意：不一定以最后一个元素结尾的就是最长的，需要遍历所有f[i]取最大
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        // 对每个位置i，以自身为起点的子序列长度至少为1
        f[i] = 1;

        // 遍历i之前的所有位置j，尝试将a[i]接在以a[j]结尾的子序列后面
        for (int j = 0; j < i; j++)
        {
            // 如果a[j] < a[i]，说明满足严格递增，可以接上
            if (a[j] < a[i])
            {
                // 以a[j]结尾的长度+1（算上a[i]自己）
                f[i] = max(f[i], f[j] + 1);
            }
        }
        // 每计算完一个f[i]，更新全局最大值
        res = max(res, f[i]);
    }

    // 最终答案：整个序列中最长严格递增子序列的长度
    cout << res << endl;
    return 0;
}

/*
 * ===== 贪心+二分优化版本：O(NlogN) =====
 * 适用于N较大(如N≥1e5)时，O(N²)会超时的情况。
 * 核心思想：维护数组q，q[len]表示长度为len的上升子序列的最小末尾值。
 * 遍历每个数x时，在q中二分查找第一个≥x的位置并替换，使末尾尽可能小。
 *
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // q[len]：长度为len的上升子序列中，最小的末尾元素值
    vector<int> q;

    for (int x : a)
    {
        // 在q中二分查找第一个 ≥ x 的位置
        auto it = lower_bound(q.begin(), q.end(), x);

        if (it == q.end())
            q.push_back(x);  // x比所有末尾都大，扩展长度
        else
            *it = x;         // 用更小的x替换，使该长度末尾更小
    }

    // q的长度即为最长上升子序列的长度
    cout << q.size() << endl;
    return 0;
}
 * ===== 贪心+二分优化版本结束 =====
 */
