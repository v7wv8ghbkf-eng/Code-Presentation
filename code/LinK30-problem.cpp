/*-----题目分析-----
 * 归并排序：
 *   给定一个长度为 n（1≤n≤100000）的整数数列，
 *   要求使用归并排序将数列从小到大排序并输出。
 *
 * 解题思路：
 *   归并排序（Merge Sort）是经典的分治算法，时间复杂度稳定为 O(n log n)，
 *   空间复杂度 O(n)（需要临时数组）。
 *
 * 算法流程：
 *   1. 递归地将数组分成左右两半，直到子区间长度为1（自然有序）
 *   2. 合并两个已排序的子区间：用双指针比较，较小的先放入临时数组
 *   3. 将临时数组复制回原数组的对应位置
 */
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

const int N = 100007;
int n;
int numbers[N], temp[N];  // temp[] 为归并过程中使用的临时数组

/*-----mergeSort函数分析-----
 * 功能：对数组 nums 在 [left, right] 区间内进行归并排序（升序）。
 *
 * 分治三步：
 *   1. 递归基：left >= right 时区间为空或单元素，已经有序，直接返回。
 *   2. 分治：取中间点 mid，分别对左半 [left, mid] 和右半 [mid+1, right] 递归排序。
 *   3. 合并：双指针 i/j 分别指向左右子区间的起始位置，
 *      每次取 nums[i] 和 nums[j] 中较小的放入 temp 数组，
 *      最后将 temp 中排好的数据复制回 nums 的对应位置。
 *
 * 设计要点：
 *   - 左右子区间内部已经有序（递归保证），合并时只需比较两个子区间当前最小元素
 *   - 合并后的数据写回原数组，供上层递归继续合并
 */
void mergeSort(int nums[], int left, int right)
{
    if(left >= right) return;  // 递归基：区间长度为0或1

    int mid = left + right >> 1;  // 取中点

    // 递归排序左右子区间（自顶向下分解，自底向上合并）
    mergeSort(nums , left , mid);
    mergeSort(nums , mid + 1 , right);

    /*-----归并（合并两个有序子区间）-----*/
    int k = 0 , i = left , j = mid + 1;
    // 双指针扫描：每次取较小的元素放入 temp
    while(i <= mid && j <= right)
    {
        if(nums[i] <= nums[j])
        {
            temp[k++] = nums[i++];
        }
        else
        {
            temp[k++] = nums[j++];
        }
    }

    // 将左半区间剩余元素（如果还有）全部追加到 temp
    while(i <= mid)
    {
        temp[k++] = nums[i++];
    }
    // 将右半区间剩余元素（如果还有）全部追加到 temp
    while(j <= right)
    {
        temp[k++] = nums[j++];
    }

    // 将 temp 中合并好的数据写回到原数组的 [left, right] 区间
    for(i = left , k = 0; i <= right; i++ , k ++)
    {
        nums[i] = temp[k];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    mergeSort(numbers, 0, n - 1);

    for(int i = 0; i < n; i ++)
    {
        printf("%d " , numbers[i]);
    }
    printf("\n");

    return 0;
}
