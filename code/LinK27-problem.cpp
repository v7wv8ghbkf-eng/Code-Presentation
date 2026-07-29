/*-----题目分析-----
 * 大数排序：
 *   给定一个长度为 n（1≤n≤100000）的整数数列，所有整数在 [1, 10^9] 范围内，
 *   要求将数列从小到大排序并输出。
 *
 * 解题思路：
 *   使用快速排序（Quick Sort）—— 平均 O(n log n)，是最通用的高效排序算法之一。
 *   本题 n 可达 10^5，冒泡排序等 O(n^2) 算法无法通过。
 *
 * 算法选择：Hoare 划分方案，以区间中点为基准元素，双指针扫描交换。
 */
#include <iostream>
using namespace std;

const int N = 1000010;
int q[N];  // 全局数组，存储待排序数据

/*-----quick_sort函数分析-----
 * 功能：对数组 nums 在 [left, right] 区间内进行快速排序（升序）。
 *
 * 算法流程（Hoare 划分）：
 *   1. 递归终止条件：left >= right，区间为空或单元素，无需排序。
 *   2. 选取基准值 x = nums[(left + right) / 2]（区间中间位置的元素）。
 *   3. 双指针 i（从左向右）、j（从右向左）扫描：
 *      - i 跳过所有小于 x 的元素（遇到 >= x 的元素停止）
 *      - j 跳过所有大于 x 的元素（遇到 <= x 的元素停止）
 *      - 若 i < j 则交换 nums[i] 和 nums[j]，继续扫描
 *   4. 指针交错后，左子区间 [left, j] 中的元素均 <= 右子区间 [j+1, right] 中的元素，
 *      递归对两个子区间分别排序。
 *
 * 注意：此处 while(i<j) + do-while 结构保证指针一定会移动，
 *   避免取到极端基准值时出现死循环。
 */
void quick_sort(int nums[], int left, int right)
{
    if (left >= right)
        return;  // 区间大小为0或1，已经有序

    int i = left - 1, j = right + 1;
    int x = nums[left + right >> 1];  // 取区间中间位置的元素作为基准

    while (i < j)
    {
        // i 右移，直到找到 >= 基准的元素
        do
        {
            i++;
        } while (nums[i] < x);

        // j 左移，直到找到 <= 基准的元素
        do
        {
            j--;
        } while (nums[j] > x);

        // 若 i < j，交换两个"站错位置"的元素
        if (i < j)
            swap(nums[i], nums[j]);
    }

    // 划分完成后，[left, j] 中的元素 ≤ [j+1, right] 中的元素
    // 递归处理左右两个子区间
    quick_sort(nums, left, j);
    quick_sort(nums, j + 1, right);
}

int main()
{
    int n;
    scanf("%d" , &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d" , &q[i]);
    }

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d " , q[i]);
    }
    printf("\n");

    return 0;
}
