/*-----题目分析-----
 * 汉诺塔问题变体：有三根杆子（由输入的三个字符指定编号），
 * A杆上有N个穿孔圆盘（从小到大编号1~N），盘的尺寸由下到上依次变小。
 * 要求按规则将所有圆盘从A移至C杆：
 *   - 每次只能移动一个圆盘
 *   - 大盘不能叠在小盘上面
 * 输入：整数N和三个单字符（分别表示三个杆子的编号）
 * 输出：每一步移动盘子的记录，格式为 编号:起始杆->目标杆
 *-----题目分析-----*/
#include<iostream>
using namespace std;

/*-----移动函数-----*/
// 外显移动过程、输出单步移动记录：将编号为n的盘子从start杆移动到target杆
void move(char start, char target, int n)
{
    cout << n << ":" << start << "->" << target << endl;
    return;
}

/*-----dfs函数分析-----*/
// dfs：将n个盘子从start杆，借助middle杆，移动到target杆
// 递归策略：将n-1个盘子的子问题委托给递归，自己只负责移动最底下的第n个盘子
// 这与Link09（汉诺塔I）不同之处在于：杆子编号由输入指定而非固定为A/B/C，
// 且输出格式包含盘子编号
void dfs(int n, char start, char middle, char target)
{
    // 递归出口：只有一个盘子时，直接从start移动到target（无需借助middle）
    if (n == 1)
    {
        move(start, target, n);
        return;
    }

    // 第一步：把上面n-1个盘子从start移动到middle（借助target作为临时杆）
    dfs(n - 1, start, target, middle);

    // 第二步：把最大的第n个盘子直接从start移动到target
    move(start, target, n);

    // 第三步：把n-1个盘子从middle移动到target（借助start作为临时杆）
    dfs(n - 1, middle, start, target);

    return;
}

int main()
{
    int n;
    char a, b, c;
    cin >> n >> a >> b >> c;    // 读入盘子数和三个杆子的编号
    dfs(n, a, b, c);            // 将n个盘子从a借助b移到c
    return 0;
}