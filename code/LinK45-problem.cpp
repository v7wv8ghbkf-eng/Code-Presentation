/*-----题目分析-----
 * 数独验证：给定一个9×9矩阵作为"记忆碎片"，判定它是否是初始矩阵A的有效解。
 * 初始矩阵A（9×9）中0表示空格，需要填入1-9使每行、每列、每个3×3宫格内数字不重复。
 * 输入的矩阵若满足：与初始矩阵A的已知数字不冲突（即非0位置不变），
 *   且每行、每列、每个宫格内无重复数字（0空格除外），则为有效解输出"Yes"，否则"No"。
 *-----题目分析-----*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 9;                        // 数独大小 9×9
const int M = 3;                        // 宫格大小 3×3

// 初始矩阵A（0表示空格，需填入1-9）
string memory[N] = {"530070000",
                    "600195000",
                    "098000060",
                    "800060003",
                    "400803001",
                    "700020006",
                    "060000280",
                    "000419005",
                    "000080079"};

int a[N][N], b[N][N];                   // a:初始矩阵，b:输入矩阵
bool st[N + 1];                         // 数字标记数组（1~9）

/*-----check_input：验证输入格式-----*/
// 读入9行字符串，每行必须是恰好9个数字字符（'0'~'9'）
bool check_input()
{
    string line;
    for (int i = 0; i < N; i++)
    {
        cin >> line;
        if (line.size() != N)           // 行长度不对（如样例3某行过长）
            return false;

        for (int j = 0; j < N; j++)
        {
            int t = line[j] - '0';
            if (t < 0 || t > N)         // 非数字字符
                return false;
            b[i][j] = t;                // 存入 b 矩阵
        }
    }
    return true;
}

/*-----check_row：检查每行是否有重复数字-----*/
bool check_row()
{
    for (int i = 0; i < N; i++)
    {
        memset(st, false, sizeof(st));
        for (int j = 0; j < N; j++)
        {
            int t = b[i][j];
            if (t < 0 || t > N) return false;
            if (t == 0) continue;       // 0 表示空格，跳过检查
            if (st[t] == true)          // 数字t已在本行出现过
                return false;
            st[t] = true;
        }
    }
    return true;
}

/*-----check_col：检查每列是否有重复数字-----*/
bool check_col()
{
    for (int i = 0; i < N; i++)
    {
        memset(st, false, sizeof(st));
        for (int j = 0; j < N; j++)
        {
            int t = b[j][i];            // 注意：行索引为j，列索引为i
            if (t < 0 || t > N) return false;
            if (t == 0) continue;
            if (st[t] == true)
                return false;
            st[t] = true;
        }
    }
    return true;
}

/*-----check_block：检查每个3×3宫格是否有重复数字-----*/
bool check_block()
{
    for (int i = 0; i < N; i += M)          // 宫格行起点：0, 3, 6
    {
        for (int j = 0; j < N; j += M)      // 宫格列起点：0, 3, 6
        {
            memset(st, false, sizeof(st));
            for (int dx = 0; dx < M; dx++)
            {
                for (int dy = 0; dy < M; dy++)
                {
                    int t = b[i + dx][j + dy];
                    if (t < 0 || t > N) return false;
                    if (t == 0) continue;
                    if (st[t] == true)
                        return false;
                    st[t] = true;
                }
            }
        }
    }
    return true;
}

int main()
{
    // 将初始矩阵A的字符串转为整数存到 a 数组
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            a[i][j] = memory[i][j] - '0';
        }
    }

    // 输入验证：格式正确是第一步
    if (!check_input())
    {
        cout << "No" << endl;
        return 0;
    }

    // 三步验证：行 → 列 → 宫格，全部通过才是有效解
    if (check_row() && check_col() && check_block())
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}