/*-----题目分析-----*/
// 给定已升序排列且无重复元素的数组 a 和目标值 target
// 找出两个元素使其和为 target，返回它们的下标 (i < j)
// 题目保证有且仅有一个答案

#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;

int main()
{
    int target, n;
    cin >> target >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    /*-----双指针（Two Pointers）解法-----*/
    // 由于数组已升序排列，可以用左右双指针在 O(n) 时间内找到答案
    // 左指针 i 指向最小值，右指针 j 指向最大值
    // 若 arr[i] + arr[j] > target → 右指针左移（减小和）
    // 若 arr[i] + arr[j] < target → 左指针右移（增大和）
    int i = 0, j = n - 1;
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum == target)
        {
            cout << i << " " << j;
            return 0;
        }
        else if (sum < target)
        {
            i++;    // 和太小，左指针右移
        }
        else
        {
            j--;    // 和太大，右指针左移
        }
    }

    return 0;
}