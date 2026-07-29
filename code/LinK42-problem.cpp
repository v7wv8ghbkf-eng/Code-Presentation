/*----- 本题题面分析-----*/
// 要求对长为w、宽为h的蛋糕进行切割；要求一共切成m块
// 题目需要不同方案切出来的m块蛋糕中，蛋糕最大面积的下限
// 朴素逻辑：对每种方案枚举，对切出来的m个蛋糕取max，再对众多方案的max值取min

/*-------代码实现-------*/

#include <iostream>
#include <cstring>
// <climits>中包含了INT_MAX,是系统设定好的极大值
#include <climits>

using namespace std;

/*-----memo记忆化-----*/
// 记忆化是剪枝的一环
// memo会存储已经确定的dfs[w][h][m]
// 这是因为在对w、h的不同切法中，总会切出来重复面对某个长宽以及某个要求切出块数
// 如果已经通过dfs得到过某个dfs的答案，那么可以不重复计算
int memo[25][25][25];

/*-----dfs函数-----*/
// 对于dfs函数如果不从递归的方式去看会好理解一些
// 也就是将其纯功能性处理(dfs是实现什么功能的)：
// dfs(w, h, m)是用来输出将长为w、宽为h的蛋糕切出来的m块蛋糕中，蛋糕最大面积的下限
// (这里特殊在本题可以只使用dfs输出答案，dfs作为函数当然也可以只实现局部功能)
int dfs(int w, int h, int m)
{
    // 如果只需要切成1块，那就是蛋糕块本身
    if (m == 1)
        return w * h;

    // memo对于未搜索的dfs组合为-1
    // res(result,dfs最终输出“结果”)是引用，相当于是简化了memo的冗长书写
    int &res = memo[w][h][m];
    if (res != -1)
        return res;

    /*-----函数主体功能分析-----*/
    // 对于dfs[w][h][m]而言，要划分任务、细分下去，取决于第一刀的切法
    // 这一刀可以横切或者竖切，并以此为依据把“切成m块”的任务分配给切出来的那两块
    // 然后再继续按照不同切法切下去
    // 不需要管递归是什么结构，只关注功能本身的实现与dfs函数的结合即可

    // best是最后我取到的结果
    // 以防第一次best在min更新中会错误导致无法选中得出的值，选个较大的数字
    int best = INT_MAX;

    // 对横切，会将宽h分为h1、h2，那么这里可以枚举和h1长度
    for (int h1 = 1; h1 < h; h1++)
    {
        // 切出来的分割为h1 + h2 = h
        int h2 = h - h1;
        // 枚举分割给h1的块数k，那么给h2的就是m - k块嘛
        for (int k = 1; k < m; k++)
        {
            // 对于长w宽h的蛋糕且切出来边长为整数，理论上只能切成1x1的大小
            // 也就是最多切成w * h块
            // 如果分配给某一边的块数太多，那么这个k就需要被跳过
            if (k > h1 * w || m - k > h2 * w)
                continue;

            // 本题这里的处理很像DP，因为是在不断优化取最优解，再在最优解的基础上更新
            // 同时不会有回头路，因为都被memo砍掉了
            int cur = max(dfs(w, h1, k), dfs(w, h2, m - k));
            best = min(best, cur);
        }
    }

    // 接下来就是竖着切
    for (int w1 = 1; w1 < w; w1++)
    {
        int w2 = w - w1;
        for (int k = 1; k < m; k++)
        {
            if (k > w1 * h || m - k > w2 * h)
                continue;

            int cur = max(dfs(w1, h, k), dfs(w2, h, m - k));
            best = min(best, cur);
        }
    }

    // 在best对两种方案分别更新过后，可以输出了
    // 但也不能忘记对以w,h,m为形参的dfs做memo记忆化储存
    return res = best;
}

int main()
{
    // 初始化记忆库memo
    memset(memo, -1, sizeof(memo));

    int w, h, m;
    while (cin >> w >> h >> m)
    {
        // 多组输入数据的结束
        if (w == 0 && h == 0 && m == 0)
            break;

        // 分别输出数据
        cout << dfs(w, h, m) << endl;
    }
    return 0;
}