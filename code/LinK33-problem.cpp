/*-----棰樼洰鍒嗘瀽-----
 * 鍦ㄥ崌搴忔暟缁刵ums涓紝瀵逛簬姣忎釜鏌ヨtarget锛屾壘鍑簍arget鍦ㄦ暟缁勪腑鐨? * 璧峰涓嬫爣鍜岀粓姝笅鏍囷紙浠?寮€濮嬭鏁帮級銆? * 鑻arget涓嶅瓨鍦ㄤ簬鏁扮粍涓紝鍒欒緭鍑?-1 -1"銆? *
 * 瑙ｆ硶锛氫袱娆′簩鍒嗘煡鎵俱€? * - findFirst锛氭煡鎵剧涓€涓瓑浜巘arget鐨勪綅缃紙宸﹁竟鐣岋級
 * - findSecond锛氭煡鎵炬渶鍚庝竴涓瓑浜巘arget鐨勪綅缃紙鍙宠竟鐣岋級
 * 鏃堕棿澶嶆潅搴︼細O(q log n)锛屽叾涓璹鏄煡璇㈡鏁般€? *-----*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

/*-----findFirst锛氫簩鍒嗘煡鎵総arget鐨勫乏杈圭晫-----*/
/* 鍔熻兘锛氬湪鍗囧簭鏁扮粍arr涓壘鍒扮涓€涓瓑浜巘arget鐨勪笅鏍囷紝鎵句笉鍒拌繑鍥?1銆? *
 * 浜屽垎绛栫暐锛? * - 褰揳rr[mid] == target鏃讹紝涓嶇珛鍗宠繑鍥烇紝鑰屾槸鏀剁缉鍙宠竟鐣?r=mid-1)锛? *   缁х画鍚戝乏鎼滅储锛岀‘淇濇渶缁堟壘鍒扮殑鏄渶宸﹀嚭鐜颁綅缃€? * - 褰揳rr[mid] < target鏃讹紝target鍦ㄥ彸鍗婇儴鍒嗭紝鏀剁缉宸﹁竟鐣?l=mid+1)銆? * - 褰揳rr[mid] > target鏃讹紝target鍦ㄥ乏鍗婇儴鍒嗭紝鏀剁缉鍙宠竟鐣?r=mid-1)銆? */
int findFirst(int target)
{
    int l = 0, r = arr.size() - 1;
    int result = -1;  // 榛樿鍊硷細鏈壘鍒?
    while (l <= r)
    {
        int mid = l + r >> 1;  // 绛変环浜?(l + r) / 2
        if (arr[mid] == target)
        {
            r = mid - 1;       // 缁х画鍚戝乏鎼滐紝鎵炬洿鏃╁嚭鐜扮殑鐩稿悓鍏冪礌
            result = mid;      // 璁板綍褰撳墠鎵惧埌鐨勪綅缃?        }
        else if (arr[mid] < target)
        {
            l = mid + 1;       // target鍦ㄥ彸鍗婇儴鍒?        }
        else
        {
            r = mid - 1;       // target鍦ㄥ乏鍗婇儴鍒?        }
    }

    return result;
}

/*-----findSecond锛氫簩鍒嗘煡鎵総arget鐨勫彸杈圭晫-----*/
/* 鍔熻兘锛氬湪鍗囧簭鏁扮粍arr涓壘鍒版渶鍚庝竴涓瓑浜巘arget鐨勪笅鏍囷紝鎵句笉鍒拌繑鍥?1銆? *
 * 浜屽垎绛栫暐锛? * - 褰揳rr[mid] == target鏃讹紝鏀剁缉宸﹁竟鐣?l=mid+1)锛? *   缁х画鍚戝彸鎼滅储锛岀‘淇濇渶缁堟壘鍒扮殑鏄渶鍙冲嚭鐜颁綅缃€? * - 鍏朵綑閫昏緫涓巉indFirst瀵圭О銆? */
int findSecond(int target)
{
    int l = 0, r = arr.size() - 1;
    int result = -1;

    while (l <= r)
    {
        int mid = l + r >> 1;
        if (arr[mid] == target)
        {
            l = mid + 1;       // 缁х画鍚戝彸鎼滐紝鎵炬洿鏅氬嚭鐜扮殑鐩稿悓鍏冪礌
            result = mid;
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return result;
}

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    arr.resize(n);

    // 璇诲叆鍗囧簭鎺掑垪鐨勬€墿缂栧彿鏁扮粍
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // 澶勭悊q娆℃煡璇?    while (q--)
    {
        int target;
        scanf("%d", &target);
        // 杈撳嚭target鍦ㄦ暟缁勪腑鐨勮捣濮嬪拰缁堟涓嬫爣
        cout << findFirst(target) << " " << findSecond(target) << endl;
    }
    return 0;
}
