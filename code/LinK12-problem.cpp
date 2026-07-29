/*-----棰樼洰鍒嗘瀽-----
 * 瀛楃鍏ㄦ帓鍒楋細缁欏畾涓€涓敱涓嶅悓灏忓啓瀛楁瘝缁勬垚鐨勫瓧绗︿覆锛岃緭鍑鸿瀛楃涓茬殑鎵€鏈夊叏鎺掑垪銆? * 杈撳叆锛氫竴琛岋紝鐢变笉鍚屽皬鍐欏瓧姣嶇粍鎴愮殑瀛楃涓诧紙闀垮害2~8锛? * 杈撳嚭锛氭墍鏈夋帓鍒楁柟寮忥紝姣忚涓€涓紝鎸夊瓧姣嶅簭鍗囧簭杈撳嚭
 * 鍏抽敭鐐癸細闇€瑕佸厛瀵硅緭鍏ュ瓧绗︿覆鎺掑簭锛屼繚璇丏FS鏋氫妇鏃舵寜瀛楀吀搴忕敓鎴愭帓鍒? *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 10;

// 杈撳叆瀛楃涓诧紙鎺掑簭鍚庯級
string str;
// used[i]锛歴tr[i]鏄惁宸茶閫夊叆褰撳墠鎺掑垪锛堝氨鏄箣鍓嶇殑st[]锛?bool used[N];
// 褰撳墠鎺掑垪璺緞锛屽鏄炬暟缁?vector<char> path;

/*-----dfs鍑芥暟鍒嗘瀽-----*/
// dfs锛氭寜瀛楀吀搴忛亶鍘嗗瓧绗︿覆鐨勬墍鏈夋帓鍒?// 閫掑綊绛栫暐锛氭瘡灞備粠鏈娇鐢ㄧ殑瀛楃涓寜椤哄簭閫夊彇涓€涓紝鍔犲叆璺緞骞舵爣璁板凡鐢?// 閫掑綊鍑哄彛锛氬綋璺緞闀垮害绛変簬瀛楃涓查暱搴︽椂锛岃緭鍑哄綋鍓嶆帓鍒?void dfs(int depth)
{
    // 閫掑綊鍑哄彛锛氬凡閫夊嚭瀹屾暣鎺掑垪锛岃緭鍑?    if (depth == (int)str.size())
    {
        for (int i = 0; i < (int)path.size(); i++)
        {
            cout << path[i];
        }
        cout << endl;
        return;
    }

    // 妯悜鏋氫妇锛氭寜椤哄簭灏濊瘯姣忎釜鏈娇鐢ㄧ殑瀛楃锛堝洜涓簊tr宸叉帓搴忥紝淇濊瘉浜嗗瓧鍏稿簭锛?    for (int i = 0; i < (int)str.size(); i++)
    {
        if (!used[i])
        {
            used[i] = true;
            path.push_back(str[i]);
            dfs(depth + 1);  // 绔栧悜娣卞叆涓嬩竴灞?            path.pop_back(); // 鍥炴函锛氭挙閿€閫夋嫨
            used[i] = false; // 鍥炴函锛氭仮澶嶆爣璁?        }
    }
}

int main()
{
    cin >> str;

    // 瀵瑰瓧绗︿覆鎺掑簭锛屼繚璇佽緭鍑烘寜瀛楀吀搴?    sort(str.begin(), str.end());

    memset(used, false, sizeof(used));
    dfs(0);
    return 0;
}