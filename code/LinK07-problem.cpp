/*-----棰樼洰鍒嗘瀽-----*/
// 缁欏畾鐩爣鍊?target 鍜屾暣鏁版暟缁?a锛屾壘鍑烘墍鏈夋弧瓒?x + y + z == target 鐨勪笁鍏冪粍
// 瑕佹眰 x < y < z锛屼笉鍏佽閲嶅涓夊厓缁勶紝鎸?x 鍗囧簭杈撳嚭
// 瀹為檯涓婂氨鏄浜嗕竴涓姹傜殑鏁帮紝鍚屾牱鍙互浣跨敤鍙屾寚閽堟潵鍑忓皯寰幆娆℃暟锛堝弻鎸囬拡鐨勬剰涔変篃灏辨槸杩欐牱锛?// 瑙ｆ硶锛氭帓搴?+ 鍥哄畾绗竴涓暟 + 鍙屾寚閽堬紙涓夋暟涔嬪拰缁忓吀瑙ｆ硶锛?// 鏃堕棿澶嶆潅搴?O(n虏)锛屽叾涓帓搴?O(n log n)锛屽弻鎸囬拡 O(n虏)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // 纭畾鐩爣鍜屾暟缁勫ぇ灏?    int target, n;
    cin >> target >> n;

    // 瑁呭～鍏冪礌
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    /*-----绗竴姝ワ細鎺掑簭-----*/
    // 鎺掑簭鏄负浜嗘柟渚夸娇鐢ㄥ弻鎸囬拡浠ュ強鍘婚噸锛堥噸澶嶆暟瀛椾細鐩搁偦锛?    sort(a.begin(), a.end());

    vector<vector<int>> result;  // 瀛樺偍鎵€鏈夋弧瓒虫潯浠剁殑涓夊厓缁?
    /*-----绗簩姝ワ細鍥哄畾绗竴涓暟锛屽弻鎸囬拡鏌ユ壘鍚庝袱涓暟-----*/
    // 鍒濆妫€绱?    for (int i = 0; i < n - 2; i++)
    {
        // 鍘婚噸锛氬鏋滃綋鍓嶆暟鍜屽墠涓€涓浉鍚岋紝璺宠繃锛堥伩鍏嶇敓鎴愰噸澶嶄笁鍏冪粍锛?        if (i > 0 && a[i] == a[i - 1])
            continue;

        // 鍥犱负瑕佹眰涓ユ牸閫掑锛?鑰屼笖鐢变簬鏄崌搴?鍘婚噸锛屾煡鎵剧粨鏋滄槸鍒嗗埆鍞竴鐨?        // 宸︽寚閽堜粠 i+1 寮€濮嬶紝鍙虫寚閽堜粠鏈熬寮€濮嬶紝鍚戜腑闂撮€艰繎
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = a[i] + a[left] + a[right];

            if (sum == target)
            {
                // 鎵惧埌涓€缁勮В锛屽瓨鍏ョ粨鏋?                result.push_back({a[i], a[left], a[right]});

                // 鍙屾寚閽堝悓鏃剁Щ鍔紝缁х画鎼滅储
                left++;
                right--;

                // 璺宠繃宸︿晶閲嶅鍊硷紙閬垮厤鐢熸垚閲嶅涓夊厓缁勶級
                while (left < right && a[left] == a[left - 1])
                    left++;
                // 璺宠繃鍙充晶閲嶅鍊?                while (left < right && a[right] == a[right + 1])
                    right--;
            }
            else if (sum < target)
            {
                // 鍜屽お灏?鈫?闇€瑕佸澶?鈫?宸︽寚閽堝彸绉伙紙鍙栨洿澶х殑鏁帮級
                left++;
            }
            else
            {
                // 鍜屽お澶?鈫?闇€瑕佸噺灏?鈫?鍙虫寚閽堝乏绉伙紙鍙栨洿灏忕殑鏁帮級
                right--;
            }
        }
    }

    /*-----绗笁姝ワ細杈撳嚭缁撴灉-----*/
    // 鐢变簬鎺掑簭鍜屽浐瀹氱涓€涓暟鐨勯亶鍘嗛『搴忥紝缁撴灉澶╃劧鎸?x 鍗囧簭
    for (auto triplet : result)
    {
        cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
    }

    return 0;
}