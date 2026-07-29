/*-----棰樼洰鍒嗘瀽-----*/
// 缁欏畾宸插崌搴忔帓鍒椾笖鏃犻噸澶嶅厓绱犵殑鏁扮粍 a 鍜岀洰鏍囧€?target
// 鎵惧嚭涓や釜鍏冪礌浣垮叾鍜屼负 target锛岃繑鍥炲畠浠殑涓嬫爣 (i < j)
// 棰樼洰淇濊瘉鏈変笖浠呮湁涓€涓瓟妗?
#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;

int main()
{
    int target, n;
    cin >> target >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    /*-----鍙屾寚閽堬紙Two Pointers锛夎В娉?----*/
    // 鐢变簬鏁扮粍宸插崌搴忔帓鍒楋紝鍙互鐢ㄥ乏鍙冲弻鎸囬拡鍦?O(n) 鏃堕棿鍐呮壘鍒扮瓟妗?    // 宸︽寚閽?i 鎸囧悜鏈€灏忓€硷紝鍙虫寚閽?j 鎸囧悜鏈€澶у€?    // 鑻?arr[i] + arr[j] > target 鈫?鍙虫寚閽堝乏绉伙紙鍑忓皬鍜岋級
    // 鑻?arr[i] + arr[j] < target 鈫?宸︽寚閽堝彸绉伙紙澧炲ぇ鍜岋級
    int i = 0, j = n - 1;
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum == target)
        {
            cout << i << " " << j;
            return 0;
        }
        else if (sum < target)
        {
            i++;    // 鍜屽お灏忥紝宸︽寚閽堝彸绉?        }
        else
        {
            j--;    // 鍜屽お澶э紝鍙虫寚閽堝乏绉?        }
    }

    return 0;
}