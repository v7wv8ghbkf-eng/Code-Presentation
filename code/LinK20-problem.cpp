/*-----棰樼洰鍒嗘瀽-----
 * 閫掑綊瀹炵幇缁勫悎鍨嬫灇涓撅細浠?~n杩檔涓暣鏁颁腑闅忔満閫夊嚭m涓紝杈撳嚭鎵€鏈夊彲鑳界殑閫夋嫨鏂规銆? * 杈撳叆锛歯, m锛?鈮鈮, n+(n-m)鈮?5锛? * 杈撳嚭锛氭寜瀛楀吀搴忚緭鍑烘墍鏈夋柟妗堬紝姣忚m涓暟鍗囧簭鎺掑垪
 * 鎬濊矾锛欴FS鏋氫妇缁勫悎锛屼粠start寮€濮嬩緷娆￠€夋暟锛岀敤depth鎺у埗閫掑綊灞傛暟锛堝嵆宸查€夋暟閲忥級
 *       鍓灊锛氬綋鍓╀綑鍙€夋暟瀛椾笉瓒充互鍑戞弧m涓椂鎻愬墠杩斿洖
 *-----棰樼洰鍒嗘瀽-----*/
#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<int> path;       // 褰撳墠缁勫悎璺緞

/*-----dfs鍑芥暟鍒嗘瀽-----*/
// dfs锛氫粠start寮€濮嬮€夋暟锛屽綋鍓嶅凡閫塪epth涓紝鏈€缁堥渶瑕侀€夋弧m涓?// 閫掑綊鍑哄彛锛歞epth == m 鏃惰緭鍑哄綋鍓嶇粍鍚?// 鍓灊绛栫暐锛氬綋鍓╀綑鍙€夋暟瀛?(n - start + 1) 涓嶈冻鍑戞弧杩橀渶鐨?(m - depth) 涓椂锛屾彁鍓嶈繑鍥?void dfs(int start, int depth)
{
    // 閫掑綊鍑哄彛锛氬凡閫夋弧m涓暟锛岃緭鍑哄綋鍓嶇粍鍚?    if (depth == m)
    {
        for (int i = 0; i < (int)path.size(); i++)
        {
            cout << path[i];
            if (i != (int)path.size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
        return;
    }

    /*-----鍓灊-----*/
    // 濡傛灉璧峰浣嶇疆宸茶秺鐣岋紝鎴栬€呭墿浣欏彲閫夋暟瀛椾笉瓒筹紝鐩存帴杩斿洖
    // 鍓╀綑鍙€夋暟瀛?= n - start + 1锛岃繕闇€閫?= m - depth
    if (start > n || depth + n - start + 1 < m)
    {
        return;
    }

    // 妯悜鏋氫妇锛氫粠start寮€濮嬩緷娆″皾璇曢€夋嫨姣忎釜鏁板姞鍏ョ粍鍚?    // i浠巗tart寮€濮嬩繚璇佷簡缁勫悎鍐呭厓绱犲崌搴忥紝閬垮厤閲嶅
    for (int i = start; i <= n; i++)
    {
        path.push_back(i);
        dfs(i + 1, depth + 1);      // 绔栧悜娣卞叆锛氫笅涓€涓暟浠巌+1寮€濮嬮€?        path.pop_back();            // 鍥炴函锛氭挙閿€閫夋嫨
    }
}

int main()
{
    cin >> n >> m;
    dfs(1, 0);      // 浠?寮€濮嬮€夛紝鍒濆宸查€?涓?    return 0;
}