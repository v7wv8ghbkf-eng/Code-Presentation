/*-----涓嶭ink11閲嶅锛屼笉鍋氭敞閲?----*/
// 浠ヤ笅娉ㄩ噴鍜屾墍鏍囪鐨勪唬鐮佷负鍙嶅閬囧埌閮ㄥ垎閫氳繃鏃犳硶瑙ｅ喅鏃讹紝Claude Code缂栬緫鐨?
/*
 * 閮ㄥ垎閫氳繃鍘熷洜鍒嗘瀽锛?
 * 1. cout << endl 姣忔閮藉埛鏂扮紦鍐插尯锛宯 杈冨ぇ鏃惰緭鍑洪噺宸ㄥぇ(n! 琛?锛屽鑷?TLE
 *    淇锛氭崲鐢?'\n'锛屽彧鍦ㄦ渶鍚庡彲鑳介渶瑕佺殑 flush 澶勭敤 endl 鎴栫瓑绋嬪簭缁撴潫鑷姩 flush
 * 2. 鏈叧闂?C/C++ IO 鍚屾锛宑in/cout 鏁堢巼浣?
 *    淇锛氭坊鍔?ios::sync_with_stdio(false); cin.tie(nullptr);
 * 3. <cstring> 涓殑 memset 鍦ㄤ弗鏍?C++ 鏍囧噯涓嬪彧淇濊瘉 std::memset 瀛樺湪
 *    淇锛氭樉寮忎娇鐢?std::memset锛堟垨鐩存帴鐢?vector<bool> 鑷姩鍒濆鍖栦负 false锛?
 * 4. dfs 鏈熬澶氫綑鐨?return; 宸茬Щ闄わ紙void 鍑芥暟鑷劧杩斿洖鍗冲彲锛?
 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<int> path;
bool st[30];

void dfs(int depth)
{
    if (depth == n)
    {
        for (int x = 0; x < n; x++)  // path.size() 鍦ㄦ澶勭瓑浠蜂簬 n锛岀洿鎺ョ敤 n 鐣ュ揩
        {
            cout << path[x];
            if (x != n - 1)
            {
                cout << ' ';  // 鍗曞瓧绗︾敤 '' 鑰岄潪 "" 鐣ュ揩
            }
        }
        cout << '\n';  // 鍏抽敭淇锛氱敤 '\n' 鏇夸唬 endl锛岄伩鍏嶆瘡琛?flush
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            path.push_back(i);
            st[i] = true;
            dfs(depth + 1);
            st[i] = false;
            path.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);  // 鍏抽棴 C/C++ IO 鍚屾锛屽ぇ骞呮彁鍗?cin/cout 閫熷害
    cin.tie(nullptr);             // 瑙ｉ櫎 cin 涓?cout 鐨勭粦瀹?
    cin >> n;
    std::memset(st, false, sizeof st);  // 鏄惧紡浣跨敤 std::memset
    dfs(0);
    return 0;
}