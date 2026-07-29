#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 10;

int n;

/*-----dfs鍑芥暟鍒嗘瀽-----*/
// dfs锛氬浠?鍒皀鐨刵涓暟鎸夌収瀛楀吀搴忚緭鍑哄叾鎵€鏈夊彲鑳界殑鎺掑垪锛堢敱棰樻剰锛?
// 浣嗗緢鏄剧劧n鏄浐瀹氬€硷紝杩欓噷浣跨敤瀹冧笉鍚堥€傦紝鑰屼笖宸茬粡璁剧疆鍏ㄥ眬鍙橀噺浜?
// 杩欓噷瀵规瘡灞傦紝閮藉睘浜庝竴涓€滈€変笉閫夋煇涓暟瀛椻€濈殑闂锛岄渶瑕佹爣璁版暟瀛椾娇鐢ㄦ儏鍐?鍚屾椂涔熼渶瑕佹暟缁勬潵瑁呭湪銆佹紨绀烘椂鐢ㄨ繃鐨勬暟瀛?
bool st[N];
vector<int> arr;
// 鍙渶瑕佸叧蹇冩槸鍚﹁Е搴曪紝杩欎篃鏄渶瑕佸彉鍔ㄥ苟缁忕敱dfs浼犻€掔殑鈥滅姸鎬佲€?
void dfs(int depth)
{
    // 鑰冭檻閫掑綊鍑哄彛鐨勬椂鍊欙紝闄や簡鑰冭檻鏈€绠€鍗曠殑瀛愰棶棰橈紝涔熷彲浠ヨ€冭檻寰幆缁撴潫/dfs鎿嶄綔缁撴潫鐨勬爣蹇?
    // 杩欐牱鐨勬爣蹇楀線寰€鍙互鎴栬€呭簲褰撻€氳繃褰㈠弬鍦ㄥ悇涓猟fs璋冪敤涓紶閫?
    if (depth == n)
    {
        for (int x = 0; x < arr.size(); x++)
        {
            cout << arr[x];
            if (x != arr.size() - 1)
                cout << " ";
        }
        cout << endl;
        return;
    }

    // 姣忔閮戒粠1寮€濮嬪埌n鏋氫妇锛岄€夋嫨杩樻病鐢ㄨ繃鐨勬暟瀛楁斁鍒板鏄炬暟缁勪腑
    for(int x = 1; x <= n; x++)
    {
        if(!st[x])
        {
            arr.push_back(x);
            st[x] = true;
            dfs(depth + 1);
            // 涓€鏁存潯璋冪敤缁撴潫锛屾仮澶嶇幇鍦猴紝涔熷氨鏄仮澶峴t鍜宎rr鐘舵€?
            st[x] = false;
            arr.pop_back();
        }
    }

    return;
}

int main()
{
    // 鍒濆鍖?
    memset(st, false, sizeof(st));

    cin >> n;
    dfs(0);
    return 0;
}