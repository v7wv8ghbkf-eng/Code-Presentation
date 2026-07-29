/*-----题目分析-----
 * 快速选择——求第 k 小的数：
 *   给定一个长度为 n（1≤n≤100000）的整数数列和一个整数 k（1≤k≤n），
 *   要求找出数列中第 k 小的数（即排序后下标为 k-1 的元素）。
 *
 * 解题思路：
 *   使用快速选择算法（Quick Select）—— 基于快速排序的分治思想。
 *   与快速排序不同，快速选择每次只需递归一侧，平均时间复杂度 O(n)。
 *
 * 算法核心：
 *   每次划分后，根据左子区间的元素个数 l = j - left + 1 来判断：
 *     - 若 l >= k，说明第 k 小的元素在左子区间 [left, j] 中
 *     - 若 l < k，说明第 k 小的元素在右子区间 [j+1, right] 中，
 *       且是右子区间的第 (k - l) 小元素
 */
#include<iostream>
using namespace std;

const int N = 100000;
int numbers[N];  // 全局数组，存储输入数列

/*-----quick_sort（快速选择）函数分析-----
 * 功能：在数组 nums 的 [left, right] 区间内找到第 k 小的数并返回其值。
 *
 * 参数说明：
 *   nums  - 待查找的数组
 *   left  - 当前搜索区间的左边界
 *   right - 当前搜索区间的右边界
 *   k     - 在当前区间内要找第几小的数（1-based）
 *
 * 流程：
 *   1. 递归基：left >= right 时区间只剩一个元素，直接返回。
 *   2. Hoare 划分：以区间中点为基准，双指针扫描交换。
 *   3. 计算左子区间长度 l = j - left + 1：
 *      - 若 l >= k → 第 k 小在左子区间，递归搜索左边
 *      - 若 l < k  → 第 k 小在右子区间，递归搜索右边，
 *        此时在右子区间要找的是第 (k - l) 小的元素
 */
int quick_sort(int nums[] , int left , int right , int k)
{
    // 递归基：区间只剩一个元素，它就是要找的第k小
    if(left >= right) return nums[left];

    int i = left - 1 , j = right + 1;
    int x = nums[left + right >> 1];  // 基准值取区间中间位置

    // Hoare 划分：小的放左边，大的放右边
    while(i < j)
    {
        do
        {
            i ++;
        } while (nums[i] < x);   // 找到左边第一个 >= x 的元素

        do
        {
            j --;
        } while (nums[j] > x);   // 找到右边第一个 <= x 的元素

        if(i < j)
        {
            swap(nums[i] , nums[j]);  // 交换两个错位的元素
        }
    }

    // l = 左子区间 [left, j] 的元素个数
    int l = j - left + 1;
    if(l >= k)
        return quick_sort(nums , left , j , k);       // 第k小在左边
    else
        return quick_sort(nums , j + 1 , right , k - l); // 第k小在右边，更新k
}

int main()
{
    int n , k;
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    cout << quick_sort(numbers , 0 , n - 1 , k);

    return 0;
}
