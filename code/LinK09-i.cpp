#include<iostream>
using namespace std;

/*-----移动函数move-----*/
// 外显移动过程，由“所在”柱子移动到“目标”柱子
inline void move(char start, char target)
{
    cout << start << "->" << target << endl;
    return;
}

/*-----递归函数分析------*/
// hamoi：将n个盘子借助middle由start移动到target
// 因为只有一个盘子移动可以不借助middle
// 汉莫塔问题一次只能移动一个盘子，所以这里的移动n个盘子意味着移动之后依然保持自下而上盘子半径的升序
void hamoi(int n, char start, char middle, char target)
{
    // 如果只移动一个盘子，那么直接移动
    // 所有复杂问题最终都会回归到最简单的子问题，所以这也是递归出口
    if(n == 1)
    {
        move(start, target);
        return;
    }

    // 首先，将n-1个盘子通过极其复杂的方式移动到middle，保持升序
    hamoi(n - 1, start, target, middle);
    // 其次，将第n个盘子移动到target作为底座
    move(start, target);
    // 最后，将n-1个盘子移动到target
    hamoi(n - 1, middle, start, target);
}

int main()
{
    int n;
    cin >> n;
    hamoi(n, 'A', 'B', 'C');
    return 0;
}