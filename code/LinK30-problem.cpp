/*-----棰樼洰鍒嗘瀽-----
 * 褰掑苟鎺掑簭锛? *   缁欏畾涓€涓暱搴︿负 n锛?鈮鈮?00000锛夌殑鏁存暟鏁板垪锛? *   瑕佹眰浣跨敤褰掑苟鎺掑簭灏嗘暟鍒椾粠灏忓埌澶ф帓搴忓苟杈撳嚭銆? *
 * 瑙ｉ鎬濊矾锛? *   褰掑苟鎺掑簭锛圡erge Sort锛夋槸缁忓吀鐨勫垎娌荤畻娉曪紝鏃堕棿澶嶆潅搴︾ǔ瀹氫负 O(n log n)锛? *   绌洪棿澶嶆潅搴?O(n)锛堥渶瑕佷复鏃舵暟缁勶級銆? *
 * 绠楁硶娴佺▼锛? *   1. 閫掑綊鍦板皢鏁扮粍鍒嗘垚宸﹀彸涓ゅ崐锛岀洿鍒板瓙鍖洪棿闀垮害涓?锛堣嚜鐒舵湁搴忥級
 *   2. 鍚堝苟涓や釜宸叉帓搴忕殑瀛愬尯闂达細鐢ㄥ弻鎸囬拡姣旇緝锛岃緝灏忕殑鍏堟斁鍏ヤ复鏃舵暟缁? *   3. 灏嗕复鏃舵暟缁勫鍒跺洖鍘熸暟缁勭殑瀵瑰簲浣嶇疆
 */
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

const int N = 100007;
int n;
int numbers[N], temp[N];  // temp[] 涓哄綊骞惰繃绋嬩腑浣跨敤鐨勪复鏃舵暟缁?
/*-----mergeSort鍑芥暟鍒嗘瀽-----
 * 鍔熻兘锛氬鏁扮粍 nums 鍦?[left, right] 鍖洪棿鍐呰繘琛屽綊骞舵帓搴忥紙鍗囧簭锛夈€? *
 * 鍒嗘不涓夋锛? *   1. 閫掑綊鍩猴細left >= right 鏃跺尯闂翠负绌烘垨鍗曞厓绱狅紝宸茬粡鏈夊簭锛岀洿鎺ヨ繑鍥炪€? *   2. 鍒嗘不锛氬彇涓棿鐐?mid锛屽垎鍒宸﹀崐 [left, mid] 鍜屽彸鍗?[mid+1, right] 閫掑綊鎺掑簭銆? *   3. 鍚堝苟锛氬弻鎸囬拡 i/j 鍒嗗埆鎸囧悜宸﹀彸瀛愬尯闂寸殑璧峰浣嶇疆锛? *      姣忔鍙?nums[i] 鍜?nums[j] 涓緝灏忕殑鏀惧叆 temp 鏁扮粍锛? *      鏈€鍚庡皢 temp 涓帓濂界殑鏁版嵁澶嶅埗鍥?nums 鐨勫搴斾綅缃€? *
 * 璁捐瑕佺偣锛? *   - 宸﹀彸瀛愬尯闂村唴閮ㄥ凡缁忔湁搴忥紙閫掑綊淇濊瘉锛夛紝鍚堝苟鏃跺彧闇€姣旇緝涓や釜瀛愬尯闂村綋鍓嶆渶灏忓厓绱? *   - 鍚堝苟鍚庣殑鏁版嵁鍐欏洖鍘熸暟缁勶紝渚涗笂灞傞€掑綊缁х画鍚堝苟
 */
void mergeSort(int nums[], int left, int right)
{
    if(left >= right) return;  // 閫掑綊鍩猴細鍖洪棿闀垮害涓?鎴?

    int mid = left + right >> 1;  // 鍙栦腑鐐?
    // 閫掑綊鎺掑簭宸﹀彸瀛愬尯闂达紙鑷《鍚戜笅鍒嗚В锛岃嚜搴曞悜涓婂悎骞讹級
    mergeSort(nums , left , mid);
    mergeSort(nums , mid + 1 , right);

    /*-----褰掑苟锛堝悎骞朵袱涓湁搴忓瓙鍖洪棿锛?----*/
    int k = 0 , i = left , j = mid + 1;
    // 鍙屾寚閽堟壂鎻忥細姣忔鍙栬緝灏忕殑鍏冪礌鏀惧叆 temp
    while(i <= mid && j <= right)
    {
        if(nums[i] <= nums[j])
        {
            temp[k++] = nums[i++];
        }
        else
        {
            temp[k++] = nums[j++];
        }
    }

    // 灏嗗乏鍗婂尯闂村墿浣欏厓绱狅紙濡傛灉杩樻湁锛夊叏閮ㄨ拷鍔犲埌 temp
    while(i <= mid)
    {
        temp[k++] = nums[i++];
    }
    // 灏嗗彸鍗婂尯闂村墿浣欏厓绱狅紙濡傛灉杩樻湁锛夊叏閮ㄨ拷鍔犲埌 temp
    while(j <= right)
    {
        temp[k++] = nums[j++];
    }

    // 灏?temp 涓悎骞跺ソ鐨勬暟鎹啓鍥炲埌鍘熸暟缁勭殑 [left, right] 鍖洪棿
    for(i = left , k = 0; i <= right; i++ , k ++)
    {
        nums[i] = temp[k];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    mergeSort(numbers, 0, n - 1);

    for(int i = 0; i < n; i ++)
    {
        printf("%d " , numbers[i]);
    }
    printf("\n");

    return 0;
}
