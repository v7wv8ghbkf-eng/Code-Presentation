/*-----题目分析-----*/
// 输入 T 组数据，每组数据第一个数为 N（该组元素个数），接着 N 个待排序整数
// 对每组数据按升序排序后输出，每组结果占一行
// 数据范围：N ≤ 1,000,000，T ≤ 100

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);    // 关闭 C/C++ IO 同步，加速大量数据读写
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);         // 直接用 n 构造，避免 resize

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];          // 读入 n 个待排序元素
        }

        sort(arr.begin(), arr.end());   // STL 排序，O(N log N)

        for (int i = 0; i < n; i++)
        {
            cout << arr[i];
            if (i != n - 1) cout << " ";   // 元素之间用空格分隔，行末无多余空格
        }
        cout << '\n';                    // 用 '\n' 而非 endl，避免频繁 flush
    }

    return 0;
}