#include<iostream>
using namespace std;

// 功能是输出：剩余n个台阶有几种走法
int dfs(int n)
{
    if(n == 0 || n == 1) return 1;
    if(n == 2) return 2;

    /*
    其实就是：
    int cur = dfs(n - 1) + dfs(n - 2);
    return cur;
    */
   // 剩余n个台阶的走法取决于上一步是怎么走的
   // 上一步要么是一级台阶跨上去、要么是两级台阶跨上去；分别剩余n - 1 / n - 2 级台阶
   // 这里的任务分配也是从根递归到叶子再加总回来
    return dfs(n - 1) + dfs(n - 2);
}

int main()
{
    int N;
    cin >> N;
    cout << dfs(N) << endl;
}