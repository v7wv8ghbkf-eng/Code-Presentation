/*-----棰樼洰鍒嗘瀽-----
 * 蹇€熼€夋嫨鈥斺€旀眰绗?k 灏忕殑鏁帮細
 *   缁欏畾涓€涓暱搴︿负 n锛?鈮鈮?00000锛夌殑鏁存暟鏁板垪鍜屼竴涓暣鏁?k锛?鈮鈮锛夛紝
 *   瑕佹眰鎵惧嚭鏁板垪涓 k 灏忕殑鏁帮紙鍗虫帓搴忓悗涓嬫爣涓?k-1 鐨勫厓绱狅級銆? *
 * 瑙ｉ鎬濊矾锛? *   浣跨敤蹇€熼€夋嫨绠楁硶锛圦uick Select锛夆€斺€?鍩轰簬蹇€熸帓搴忕殑鍒嗘不鎬濇兂銆? *   涓庡揩閫熸帓搴忎笉鍚岋紝蹇€熼€夋嫨姣忔鍙渶閫掑綊涓€渚э紝骞冲潎鏃堕棿澶嶆潅搴?O(n)銆? *
 * 绠楁硶鏍稿績锛? *   姣忔鍒掑垎鍚庯紝鏍规嵁宸﹀瓙鍖洪棿鐨勫厓绱犱釜鏁?l = j - left + 1 鏉ュ垽鏂細
 *     - 鑻?l >= k锛岃鏄庣 k 灏忕殑鍏冪礌鍦ㄥ乏瀛愬尯闂?[left, j] 涓? *     - 鑻?l < k锛岃鏄庣 k 灏忕殑鍏冪礌鍦ㄥ彸瀛愬尯闂?[j+1, right] 涓紝
 *       涓旀槸鍙冲瓙鍖洪棿鐨勭 (k - l) 灏忓厓绱? */
#include<iostream>
using namespace std;

const int N = 100000;
int numbers[N];  // 鍏ㄥ眬鏁扮粍锛屽瓨鍌ㄨ緭鍏ユ暟鍒?
/*-----quick_sort锛堝揩閫熼€夋嫨锛夊嚱鏁板垎鏋?----
 * 鍔熻兘锛氬湪鏁扮粍 nums 鐨?[left, right] 鍖洪棿鍐呮壘鍒扮 k 灏忕殑鏁板苟杩斿洖鍏跺€笺€? *
 * 鍙傛暟璇存槑锛? *   nums  - 寰呮煡鎵剧殑鏁扮粍
 *   left  - 褰撳墠鎼滅储鍖洪棿鐨勫乏杈圭晫
 *   right - 褰撳墠鎼滅储鍖洪棿鐨勫彸杈圭晫
 *   k     - 鍦ㄥ綋鍓嶅尯闂村唴瑕佹壘绗嚑灏忕殑鏁帮紙1-based锛? *
 * 娴佺▼锛? *   1. 閫掑綊鍩猴細left >= right 鏃跺尯闂村彧鍓╀竴涓厓绱狅紝鐩存帴杩斿洖銆? *   2. Hoare 鍒掑垎锛氫互鍖洪棿涓偣涓哄熀鍑嗭紝鍙屾寚閽堟壂鎻忎氦鎹€? *   3. 璁＄畻宸﹀瓙鍖洪棿闀垮害 l = j - left + 1锛? *      - 鑻?l >= k 鈫?绗?k 灏忓湪宸﹀瓙鍖洪棿锛岄€掑綊鎼滅储宸﹁竟
 *      - 鑻?l < k  鈫?绗?k 灏忓湪鍙冲瓙鍖洪棿锛岄€掑綊鎼滅储鍙宠竟锛? *        姝ゆ椂鍦ㄥ彸瀛愬尯闂磋鎵剧殑鏄 (k - l) 灏忕殑鍏冪礌
 */
int quick_sort(int nums[] , int left , int right , int k)
{
    // 閫掑綊鍩猴細鍖洪棿鍙墿涓€涓厓绱狅紝瀹冨氨鏄鎵剧殑绗琸灏?    if(left >= right) return nums[left];

    int i = left - 1 , j = right + 1;
    int x = nums[left + right >> 1];  // 鍩哄噯鍊煎彇鍖洪棿涓棿浣嶇疆

    // Hoare 鍒掑垎锛氬皬鐨勬斁宸﹁竟锛屽ぇ鐨勬斁鍙宠竟
    while(i < j)
    {
        do
        {
            i ++;
        } while (nums[i] < x);   // 鎵惧埌宸﹁竟绗竴涓?>= x 鐨勫厓绱?
        do
        {
            j --;
        } while (nums[j] > x);   // 鎵惧埌鍙宠竟绗竴涓?<= x 鐨勫厓绱?
        if(i < j)
        {
            swap(nums[i] , nums[j]);  // 浜ゆ崲涓や釜閿欎綅鐨勫厓绱?        }
    }

    // l = 宸﹀瓙鍖洪棿 [left, j] 鐨勫厓绱犱釜鏁?    int l = j - left + 1;
    if(l >= k)
        return quick_sort(nums , left , j , k);       // 绗琸灏忓湪宸﹁竟
    else
        return quick_sort(nums , j + 1 , right , k - l); // 绗琸灏忓湪鍙宠竟锛屾洿鏂発
}

int main()
{
    int n , k;
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    cout << quick_sort(numbers , 0 , n - 1 , k);

    return 0;
}
