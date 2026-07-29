/*-----题目分析-----
 * 给定一个16位十进制数，将其视为二进制后，找出最低位的1出现的位置（0-indexed）。
 * 例如：9 = 1001₂，最低位的1在第0位；8 = 1000₂，最低位的1在第3位。
 *
 * 解法：打表法 + lowbit
 *   1. lowbit(n) 提取最低位的1所代表的值（即 2^k）
 *   2. 用打表法快速求出 log₂(2^k) = k，即最低位1的位置
 *      Log[2^k] = k，对于 k = 0~15 预先建立映射
 *-----题目分析-----*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 16;               // 16位数，lowbit结果只有16种可能（2^0 ~ 2^15）
int Log[1 << N];                // 打表数组：Log[2^k] = k

/*-----buildList函数-----*/
// 建立 lowbit 结果到位置的映射表
// 只对 2^0, 2^1, ..., 2^15 这16个值建立映射，其余位置初始化为 -1
void buildList()
{
    // 先全部初始化为 -1（未检索到此位置）
    memset(Log, -1, sizeof(Log));

    // 建立映射：Log[2^i] = i，即 2^i 的最低1位在第 i 位
    for (int i = 0; i < N; i++)
    {
        Log[1 << i] = i;
    }
}

/*-----lowbit函数-----*/
// 返回 n 的二进制中最低位的1所代表的值
int lowbit(int n)
{
    return n & -n;
}

/*-----query函数-----*/
// 查询 n 的二进制中最低位1的位置（0-indexed）
// 先提取最低位的1的值（如8→8），再通过打表查出位置（8→3）
int query(int n)
{
    if (n == 0) return -1;          // 0 没有1，返回 -1
    return Log[lowbit(n)];          // O(1) 查表
}

int main()
{
    buildList();
    int n;
    cin >> n;
    cout << query(n) << endl; 
    return 0;
}