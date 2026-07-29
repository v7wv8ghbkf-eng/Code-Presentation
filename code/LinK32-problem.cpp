/*-----棰樼洰鍒嗘瀽-----
 * 缁欏畾N涓€墿鐨勭紪鍙凤紙鍙兘浼氭湁閲嶅锛夛紝瀵逛簬姣忎釜鏌ヨtarget锛? * 闇€瑕佽緭鍑鸿缂栧彿鎬墿鍦ㄦ暟缁勪腑鐨勪笅鏍囦綅缃€傝嫢涓嶅瓨鍦ㄥ垯杈撳嚭-1銆? *
 * 瑙ｆ硶锛氫娇鐢╱nordered_map寤虹珛"缂栧彿鈫掍笅鏍?鐨勫搱甯屾槧灏勶紝瀹炵幇O(1)鏌ヨ銆? * 娉ㄦ剰锛氳嫢瀛樺湪閲嶅缂栧彿锛宮ap淇濈暀鐨勬槸鏈€鍚庝竴娆″嚭鐜扮殑涓嬫爣锛? *       鑻ラ鐩姹傝繑鍥炵涓€娆″嚭鐜扮殑浣嶇疆锛屽垯闇€鏀圭敤"鍙彃鍏ヤ笉瑕嗙洊"鐨勭瓥鐣ャ€? *-----*/

#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    int N;
    cin >> N;

    unordered_map<int, int> mp;  // 缂栧彿 -> 涓嬫爣鐨勫搱甯屾槧灏?
    // 璇诲叆姣忎釜鎬墿鐨勭紪鍙凤紝寤虹珛鏄犲皠
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        mp[x] = i;  // 瀛樺偍缂栧彿x鍑虹幇鐨勬渶鏂颁綅缃?    }

    int T;
    cin >> T;

    // 澶勭悊T娆℃煡璇?    while (T--)
    {
        int target;
        cin >> target;

        auto it = mp.find(target);

        if (it != mp.end())
        {
            cout << it->second << endl;  // 鎵惧埌鐩爣锛岃緭鍑哄搴斾笅鏍?        }
        else
        {
            cout << -1 << endl;  // 鏈壘鍒扮洰鏍囩紪鍙?        }
    }

    return 0;
}
