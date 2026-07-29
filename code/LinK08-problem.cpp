/*-----题目分析-----*/
// 给定目标值 target 和整数数组 A，找出所有满足 a + b + c + d == target 的四元组
// 要求 a < b < c < d，不允许重复四元组，按 a → b → c → d 优先级升序输出
// （多加一层循环而已）
// 解法：排序 + 固定前两个数 + 双指针（四数之和经典解法）
// 时间复杂度 O(n³)，其中双指针 O(n)，外层固定两个数 O(n²)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int target, n;
    cin >> target >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    /*-----第一步：排序-----*/
    // 排序确保去重简单（重复数字相邻）且双指针策略有效
    sort(A.begin(), A.end());

    vector<vector<int>> result;  // 存储所有满足条件的四元组

    /*-----第二步：固定第一个数-----*/
    for (int i = 0; i < n - 3; i++)
    {
        // 去重：跳过与前一元素相同的值，避免生成重复四元组
        if (i > 0 && A[i] == A[i - 1])
            continue;

        /*-----第三步：固定第二个数-----*/
        for (int j = i + 1; j < n - 2; j++)
        {
            // 去重：跳过与前一元素相同的值
            if (j > i + 1 && A[j] == A[j - 1])
                continue;

            /*-----第四步：双指针查找后两个数-----*/
            int left = j + 1;      // 左指针从 j+1 开始
            int right = n - 1;     // 右指针从末尾开始

            while (left < right)
            {
                int sum = A[i] + A[j] + A[left] + A[right];

                if (sum == target)
                {
                    result.push_back({A[i], A[j], A[left], A[right]});

                    left++;
                    right--;

                    // 跳过左侧重复值
                    while (left < right && A[left] == A[left - 1])
                        left++;
                    // 跳过右侧重复值
                    while (left < right && A[right] == A[right + 1])
                        right--;
                }
                else if (sum < target)
                {
                    left++;     // 和太小 → 左指针右移增大和
                }
                else
                {
                    right--;    // 和太大 → 右指针左移减小和
                }
            }
        }
    }

    /*-----第五步：输出结果-----*/
    // 由于固定数的遍历顺序和排序，结果天然按 a → b → c → d 升序
    for (auto quadruplet : result)
    {
        cout << quadruplet[0] << " " << quadruplet[1] << " "
             << quadruplet[2] << " " << quadruplet[3] << endl;
    }

    return 0;
}