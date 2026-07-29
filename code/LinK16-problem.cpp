#include <iostream>
#include <cstring>
using namespace std;

// 鍓灊锛氳蹇嗗寲
int memo[35][20];

/*-----dfs鍑芥暟鍒嗘瀽-----*/
// dfs锛氬鍓╀綑鐨刴涓嫻鏋滃拰n涓洏瀛愭湁鍑犵鏀炬硶
int dfs(int m, int n)
{
    // 濡傛灉娌℃湁鑻规灉锛屽彧鑳芥槸鍏ㄧ┖
    if (m == 0)
        return 1;
    // 濡傛灉娌℃湁鐩樺瓙锛屼笉瀛樺湪鏀炬硶
    if (n == 0)
        return 0;
    // 濡傛灉鍙湁涓€涓洏瀛愶紝瀛樺湪鍞竴鏀炬硶
    if (n == 1)
        return 1;

    if (memo[m][n] != -1) return memo[m][n];

    int res = 0;
    // 濡傛灉鑻规灉涓暟鏇村皯锛岄偅涔堝彧瀛樺湪鏀句笉婊＄殑鎯呭喌
    // 涓轰簡纭繚鍙€冭檻鈥滃瓨鍦ㄧ┖鐩樺瓙鈥濓紝鐩存帴灏嗗繀鐒剁┖鐨刴 - n涓洏瀛愪涪鎺?
    // 鍓╀笅鐨勭洏瀛愭槸缁х画鐣欐湁绌虹洏瀛愯繕鏄叏鏀炬弧锛岄偅鏄痙fs闇€瑕佽€冭檻鐨勯棶棰?
    if (m < n)
        res += dfs(m, m);
    else
    {
        // 灏嗏€滃瓨鍦ㄧ┖鐩樺瓙鈥濅笌鈥滀笉瀛樺湪绌虹洏瀛愮殑鏀炬硶鈥濆姞璧锋潵
        res += dfs(m, n - 1) + dfs(m - n, n);
    }
    
    memo[m][n] = res;
    return res;
}

int main()
{
    // 鍒濆鍖栦负鈥滄湭妫€绱⑩€?-1
    memset(memo, -1, sizeof(memo));

    int t;
    cin >> t;
    while (t--)
    {
        // M涓嫻鏋滐紝鏀惧湪N涓洏瀛愰噷锛屽厑璁告湁鐩樺瓙绌虹潃
        int M, N;
        cin >> M >> N;

        cout << dfs(M, N) << endl;
    }

    return 0;
}