/*-----题目分析-----
 * 输出前 k 大的数：
 *   给定一个长度为 n（n < 100000）的整数数组和一个整数 k（k < n），
 *   要求找出前 k 大的数，并从大到小输出，每个数占一行。
 *
 * 解题思路（STL nth_element 解法）：
 *   直接使用 C++ STL 中的 nth_element，其内部采用 Introselect 算法
 *   （快速选择 + 堆排序的混合），保证最坏情况 O(n) 的时间复杂度。
 *
 * 步骤：
 *   1. 用 nth_element 将第 n-k 小的元素放到 nums[n-k] 位置，
 *      同时保证 [n-k, n) 区间的元素是前 k 大的数（内部未排序）。
 *   2. 对 [n-k, n) 区间用 sort + greater<int>() 从大到小排序。
 *   3. 依次输出。
 *
 * 注意：原注释中保留了之前错误尝试的代码（已注释），仅供参考。
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100000;
int numbers[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    int k;
    scanf("%d", &k);

    /*-----STL nth_element 快速划分-----
     * nth_element 重新排列数组，使得：
     *   - numbers[n-k] 处的元素等于完全排序后该位置的元素
     *   - numbers[n-k] 左侧的元素都 ≤ 它，右侧的元素都 ≥ 它
     * 这样 [n-k, n) 区间就包含了前 k 大的数（但内部无序）。
     *
     * 内部使用 Introselect（快速选择 + 堆排序备选），
     * 保证即使在最坏情况下也是 O(n)。
     */
    nth_element(numbers, numbers + n - k, numbers + n);

    // 将前k大的数从大到小排列
    sort(numbers + n - k, numbers + n, greater<int>());

    // 输出前k大的数，每行一个
    for (int i = n - k; i < n; i++) {
        printf("%d\n", numbers[i]);
    }
    return 0;
}
