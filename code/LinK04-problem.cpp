/*-----棰樼洰鍒嗘瀽-----*/
// 杈撳叆 T 缁勬暟鎹紝姣忕粍鏁版嵁绗竴涓暟涓?N锛堣缁勫厓绱犱釜鏁帮級锛屾帴鐫€ N 涓緟鎺掑簭鏁存暟
// 瀵规瘡缁勬暟鎹寜鍗囧簭鎺掑簭鍚庤緭鍑猴紝姣忕粍缁撴灉鍗犱竴琛?// 鏁版嵁鑼冨洿锛歂 鈮?1,000,000锛孴 鈮?100

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);    // 鍏抽棴 C/C++ IO 鍚屾锛屽姞閫熷ぇ閲忔暟鎹鍐?    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);         // 鐩存帴鐢?n 鏋勯€狅紝閬垮厤 resize

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];          // 璇诲叆 n 涓緟鎺掑簭鍏冪礌
        }

        sort(arr.begin(), arr.end());   // STL 鎺掑簭锛孫(N log N)

        for (int i = 0; i < n; i++)
        {
            cout << arr[i];
            if (i != n - 1) cout << " ";   // 鍏冪礌涔嬮棿鐢ㄧ┖鏍煎垎闅旓紝琛屾湯鏃犲浣欑┖鏍?        }
        cout << '\n';                    // 鐢?'\n' 鑰岄潪 endl锛岄伩鍏嶉绻?flush
    }

    return 0;
}