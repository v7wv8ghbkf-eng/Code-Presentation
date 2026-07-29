/*-----题目分析-----
 * 数独求解（二进制状态压缩 + 优化搜索顺序）：
 * 与LinK46数独问题相同，但增加了以下优化：
 *   1. 用9位二进制整数（bit 0~8 → 数字1~9）表示行/列/宫格的数字可用状态
 *      1表示该数字可用，0表示已被占用。三方取交集只需一次 & 运算。
 *   2. 优化搜索顺序：每次选择可选数字最少的空格填入（最少分支优先），
 *      用 ones[] 打表快速查询二进制中1的个数。
 *   3. 用 map[] 和 lowbit 快速定位最低位1所在位置。
 * 输入：多组测试数据，每组一个81字符的字符串（'.'表示空格），以字符'e'结束。
 *-----题目分析-----*/
#include <iostream>
using namespace std;

const int N = 9, M = 1 << N;            // M = 512（2^9）

/*-----二进制状态压缩-----*/
// row[x]：第x行当前可用数字的9位二进制（bit t=1表示数字t+1可用）
// col[y]：第y列当前可用数字的9位二进制
// cell[i][j]：第(i,j)宫格当前可用数字的9位二进制
int row[N], col[N], cell[3][3];

char str[100];                          // 输入字符串（81字符，9×9）
int ones[M];                            // ones[i]：二进制数i中1的个数（打表）
int map[M];                             // map[1<<t] = t，快速定位最低位1的位置

/*-----lowbit函数-----*/
// 返回x的二进制中最低位的1所代表的值
inline int lowbit(int x)
{
    return x & -x;
}

/*-----get函数-----*/
// 获取坐标(x,y)处可用数字的二进制状态（行、列、宫三方取交集）
inline int get(int x, int y)
{
    return row[x] & col[y] & cell[x / 3][y / 3];
}

/*-----init函数-----*/
// 初始化：建立map查询表和ones计数表，将所有行/列/宫格初始化为全可用（M-1 = 511 = 111111111₂）
void init()
{
    // 建立map：map[2^i] = i，即二进制位 → 数字索引
    for (int i = 0; i < N; i++)
    {
        map[1 << i] = i;
    }

    // 建立ones：统计每个9位二进制中1的个数
    for (int i = 0; i < M; i++)
    {
        ones[i] = 0;                    // 多测例时需归零
        for (int j = i; j; j -= lowbit(j))
        {
            ones[i]++;
        }
    }

    // 初始化所有行/列/宫格为全可用
    for (int i = 0; i < N; i++)
    {
        row[i] = col[i] = M - 1;        // M-1 = 511 = 111111111₂（9位全1）
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cell[i][j] = M - 1;
        }
    }
}

/*-----dfs函数分析-----*/
// dfs：还剩cnt个空格需要填充，每次选择可选数字最少的空格进行尝试
//      这样能最大化剪枝效果（分支数最小），这是"优化搜索顺序"策略
// 返回值：bool，找到任一解即返回true终止搜索
bool dfs(int cnt)
{
    // 递归出口：所有空格已填完
    if (!cnt)
        return true;

    /*-----优化搜索顺序：找可选数字最少的空格-----*/
    int minv = 10;                      // 最少可选数，初始化为大于9的值
    int x = 0, y = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (str[i * 9 + j] == '.')
            {
                int t = ones[get(i, j)];  // 该空格有多少个可用数字

                if (t < minv)             // 打擂台取最少分支
                {
                    minv = t;
                    x = i, y = j;
                }
            }
        }
    }

    /*-----枚举所有可用数字-----*/
    // 对当前格子的每个可用位（1的位置），尝试填入对应数字
    for (int i = get(x, y); i; i -= lowbit(i))
    {
        int t = map[lowbit(i)];         // 取出最低位1对应的数字索引（0~8 → 数字1~9）

        // 标记占用：将该数字从行/列/宫格的可用集合中移除
        row[x] -= 1 << t;
        col[y] -= 1 << t;
        cell[x / 3][y / 3] -= 1 << t;
        str[x * 9 + y] = '1' + t;       // 填入数字（索引0→数字1）

        if (dfs(cnt - 1))               // 递归，如果找到解则逐层返回
            return true;

        // 回溯：恢复占用标记
        row[x] += 1 << t;
        col[y] += 1 << t;
        cell[x / 3][y / 3] += 1 << t;
        str[x * 9 + y] = '.';
    }

    return false;                       // 所有数字都不可行
}

int main()
{
    // 多组测试数据，以字符'e'开头结束
    while (cin >> str, str[0] != 'e')
    {
        init();

        int cnt = 0;                    // 统计空格数量

        /*-----读入初始棋盘，设置占用状态-----*/
        // k = i*9+j 为一维字符串索引，遍历81个字符
        for (int i = 0, k = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++, k++)
            {
                if (str[k] != '.')
                {
                    // 已有数字：将其从行/列/宫格的可用集合中移除
                    int t = str[k] - '1';   // 数字→索引（0~8）
                    row[i] -= 1 << t;
                    col[j] -= 1 << t;
                    cell[i / 3][j / 3] -= 1 << t;
                }
                else
                {
                    cnt++;                  // 空格计数
                }
            }
        }

        dfs(cnt);                       // 从cnt个空格开始搜索

        cout << str << endl;            // 输出填补后的完整棋盘
    }

    return 0;
}