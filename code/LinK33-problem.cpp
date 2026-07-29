/*-----题目分析-----
 * 在升序数组nums中，对于每个查询target，找出target在数组中的
 * 起始下标和终止下标（从0开始计数）。
 * 若target不存在于数组中，则输出"-1 -1"。
 *
 * 解法：两次二分查找。
 * - findFirst：查找第一个等于target的位置（左边界）
 * - findSecond：查找最后一个等于target的位置（右边界）
 * 时间复杂度：O(q log n)，其中q是查询次数。
 *-----*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

/*-----findFirst：二分查找target的左边界-----*/
/* 功能：在升序数组arr中找到第一个等于target的下标，找不到返回-1。
 *
 * 二分策略：
 * - 当arr[mid] == target时，不立即返回，而是收缩右边界(r=mid-1)，
 *   继续向左搜索，确保最终找到的是最左出现位置。
 * - 当arr[mid] < target时，target在右半部分，收缩左边界(l=mid+1)。
 * - 当arr[mid] > target时，target在左半部分，收缩右边界(r=mid-1)。
 */
int findFirst(int target)
{
    int l = 0, r = arr.size() - 1;
    int result = -1;  // 默认值：未找到

    while (l <= r)
    {
        int mid = l + r >> 1;  // 等价于 (l + r) / 2
        if (arr[mid] == target)
        {
            r = mid - 1;       // 继续向左搜，找更早出现的相同元素
            result = mid;      // 记录当前找到的位置
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;       // target在右半部分
        }
        else
        {
            r = mid - 1;       // target在左半部分
        }
    }

    return result;
}

/*-----findSecond：二分查找target的右边界-----*/
/* 功能：在升序数组arr中找到最后一个等于target的下标，找不到返回-1。
 *
 * 二分策略：
 * - 当arr[mid] == target时，收缩左边界(l=mid+1)，
 *   继续向右搜索，确保最终找到的是最右出现位置。
 * - 其余逻辑与findFirst对称。
 */
int findSecond(int target)
{
    int l = 0, r = arr.size() - 1;
    int result = -1;

    while (l <= r)
    {
        int mid = l + r >> 1;
        if (arr[mid] == target)
        {
            l = mid + 1;       // 继续向右搜，找更晚出现的相同元素
            result = mid;
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return result;
}

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    arr.resize(n);

    // 读入升序排列的怪物编号数组
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // 处理q次查询
    while (q--)
    {
        int target;
        scanf("%d", &target);
        // 输出target在数组中的起始和终止下标
        cout << findFirst(target) << " " << findSecond(target) << endl;
    }
    return 0;
}
