/*-----题目分析-----*/
// 12枚硬币（A-L），其中11枚真币、1枚假币（不知轻重）
// 经过3次称量，根据天平结果找出假币并判断其轻重
// 解法：枚举法——对每枚硬币假设其为轻或重，验证是否满足三次称量结果

#include <iostream>
#include <string>
using namespace std;

/*-----称量数据结构-----*/
struct weigh
{
    string left;    // 天平左边放置的硬币
    string right;   // 天平右边放置的硬币
    string result;  // 天平结果：even(平衡) / up(右高，即左重) / down(右低，即左轻)
};

/*-----check函数分析-----*/
// 假设硬币 coin 是假币，且 isLight 为 true 表示假币较轻、false 表示假币较重
// 对三次称量结果逐一验证，如果全部符合则假设成立
bool check(char coin, bool isLight, weigh w[])
{
    for (int i = 0; i < 3; i++)
    {
        string l = w[i].left;
        string r = w[i].right;
        string res = w[i].result;

        // 统计左右两边的"重量"：只在含有假设假币的那一侧进行加减
        // 真币重量记0，假币根据假设：轻为-1、重为+1
        int leftWeight = 0, rightWeight = 0;

        // 这里直接通过“是否包含假币”和“假设的假币轻重”来改变先决为平衡的左右重量
        // 可以这么操作是因为只包含一枚假币，天平平衡也只和这枚假币有关
        
        // 检查天平左侧是否包含假设的假币
        for (char c : l)
        {
            if (c == coin)
            {
                // 假币轻 → 左侧重量-1；假币重 → 左侧重量+1
                leftWeight += (isLight ? -1 : 1);
            }
        }

        // 检查天平右侧是否包含假设的假币
        for (char c : r)
        {
            if (c == coin)
            {
                // 假币在右侧：轻 → 右侧-1；重 → 右侧+1
                rightWeight += (isLight ? -1 : 1);
            }
        }

        /*-----根据天平结果验证假设-----*/
        // even：两边重量必须相等
        if (res == "even")
        {
            if (leftWeight != rightWeight)
                return false;
        }
        // up（右端高=左端重）：左侧重量必须 > 右侧重量
        else if (res == "up")
        {
            if (leftWeight <= rightWeight)
                return false;
        }
        // down（右端低=左端轻）：左侧重量必须 < 右侧重量
        else if (res == "down")
        {
            if (leftWeight >= rightWeight)
                return false;
        }
    }

    return true;    // 三次称量全部符合假设
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        weigh w[3];
        for (int i = 0; i < 3; i++)
        {
            cin >> w[i].left >> w[i].right >> w[i].result;
        }

        // 枚举12枚硬币 A-L，对每枚分别假设其为轻和重
        for (char c = 'A'; c <= 'L'; c++)
        {
            if (check(c, true, w))      // 假设 c 是轻的假币
            {
                cout << c << " is the counterfeit coin and it is light." << endl;
                break;
            }
            if (check(c, false, w))     // 假设 c 是重的假币
            {
                cout << c << " is the counterfeit coin and it is heavy." << endl;
                break;
            }
        }
    }

    return 0;
}