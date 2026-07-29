/*-----题目分析-----*/
// 题目要求输入蛋糕塔总体积V、蛋糕塔层数N，输出最小表面积S
// 从功能性的角度上来说，这也是dfs的输入和输出
#include <iostream>
#include <climits>
#include<cmath>
using namespace std;

int V, N;

/*------dfs函数分析-----*/
// dfs:对给定的层数N，总体积V;输出最小表面积S
/*
本题与黄金蛋糕人马的区别在于串行堆叠、并行分割
切蛋糕时候对每一个枚举出来的左右/上下两块，都还存在无数的切法（因为还存在横竖切法不同+要求块数不同）
但蛋糕塔将其分为上下两层是没有意义的，因为“层数分配”与“半径与高度的递增”关联不大
dfs必然包括r、h的限制并且能够通过dfs本身传递，同时也能包括v、n的确定
所以蛋糕塔问题是基于处理完本层+继续进行下一层来迭代的
*/

int dfs(int v, int n, int last_r, int last_h)
{
    // 如果层数为0，说明不需要继续递归了；如果v == 0，那么本层就是啥都没有；如果还有剩下的体积没用完
    if (n == 0)
        return v == 0 ? 0 : INT_MAX;

    // 对本层的r、h进行枚举 
    // 由于是自下而上枚举的，是for(上限;下限;递减)
    
    int best = INT_MAX;
    // r为什么必然大于层数n?因为如果r == n，那么接下来的每一层都是层半径最小值1，如果r小于n，那么剩下的层中会存在小数或者0，是不可取的
    // h的下限也是同理
    // r的上限是上一层半径限制（传参会减1，所以可以等于）和本层体积开方这两者中更小的那个
    // h的上限是对已经选的r，如果恰好能撑满v的高度
    // 之所以上限需要取min，是因为如果后面的外加限制大于last会出问题；而如果外加限制更小，那么就必须用这个外加限制
    for (int r = min(last_r, (int)sqrt(v)); r >= n; r--)
    {
        for (int h = min(last_h, v / (r * r)); h >= n; h--)
        {
            int cur = 2 * r * h;
            int sub =  dfs(v - r * r * h, n - 1, r - 1, h - 1);
            if(sub != INT_MAX)
            best = min(best, cur + sub);
        }
    }
    return best;
}

int main()
{
    cin >> V >> N;
    cout << dfs(V, N, (int)sqrt(V), V + 1) << endl;;
    return 0;
}