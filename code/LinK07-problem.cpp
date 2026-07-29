/*-----题目分析-----*/
// 给定目标值 target 和整数数组 a，找出所有满足 x + y + z == target 的三元组
// 要求 x < y < z，不允许重复三元组，按 x 升序输出
// 实际上就是多了一个要求的数，同样可以使用双指针来减少循环次数（双指针的意义也就是这样）
// 解法：排序 + 固定第一个数 + 双指针（三数之和经典解法）
// 时间复杂度 O(n²)，其中排序 O(n log n)，双指针 O(n²)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // 确定目标和数组大小
    int target, n;
    cin >> target >> n;

    // 装填元素
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    /*-----第一步：排序-----*/
    // 排序是为了方便使用双指针以及去重（重复数字会相邻）
    sort(a.begin(), a.end());

    vector<vector<int>> result;  // 存储所有满足条件的三元组

    /*-----第二步：固定第一个数，双指针查找后两个数-----*/
    // 初始检索
    for (int i = 0; i < n - 2; i++)
    {
        // 去重：如果当前数和前一个相同，跳过（避免生成重复三元组）
        if (i > 0 && a[i] == a[i - 1])
            continue;

        // 因为要求严格递增， 而且由于是升序+去重，查找结果是分别唯一的
        // 左指针从 i+1 开始，右指针从末尾开始，向中间逼近
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = a[i] + a[left] + a[right];

            if (sum == target)
            {
                // 找到一组解，存入结果
                result.push_back({a[i], a[left], a[right]});

                // 双指针同时移动，继续搜索
                left++;
                right--;

                // 跳过左侧重复值（避免生成重复三元组）
                while (left < right && a[left] == a[left - 1])
                    left++;
                // 跳过右侧重复值
                while (left < right && a[right] == a[right + 1])
                    right--;
            }
            else if (sum < target)
            {
                // 和太小 → 需要增大 → 左指针右移（取更大的数）
                left++;
            }
            else
            {
                // 和太大 → 需要减小 → 右指针左移（取更小的数）
                right--;
            }
        }
    }

    /*-----第三步：输出结果-----*/
    // 由于排序和固定第一个数的遍历顺序，结果天然按 x 升序
    for (auto triplet : result)
    {
        cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
    }

    return 0;
}