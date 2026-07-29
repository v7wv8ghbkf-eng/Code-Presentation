/*-----题目分析-----
 * 给定N个怪物的编号（可能会有重复），对于每个查询target，
 * 需要输出该编号怪物在数组中的下标位置。若不存在则输出-1。
 *
 * 解法：使用unordered_map建立"编号→下标"的哈希映射，实现O(1)查询。
 * 注意：若存在重复编号，map保留的是最后一次出现的下标；
 *       若题目要求返回第一次出现的位置，则需改用"只插入不覆盖"的策略。
 *-----*/

#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    int N;
    cin >> N;

    unordered_map<int, int> mp;  // 编号 -> 下标的哈希映射

    // 读入每个怪物的编号，建立映射
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        mp[x] = i;  // 存储编号x出现的最新位置
    }

    int T;
    cin >> T;

    // 处理T次查询
    while (T--)
    {
        int target;
        cin >> target;

        auto it = mp.find(target);

        if (it != mp.end())
        {
            cout << it->second << endl;  // 找到目标，输出对应下标
        }
        else
        {
            cout << -1 << endl;  // 未找到目标编号
        }
    }

    return 0;
}
