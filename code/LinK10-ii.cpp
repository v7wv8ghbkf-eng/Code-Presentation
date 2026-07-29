/*-----棰樼洰鍒嗘瀽-----
 * 姹夎濉旈棶棰樺彉浣擄細鏈変笁鏍规潌瀛愶紙鐢辫緭鍏ョ殑涓変釜瀛楃鎸囧畾缂栧彿锛夛紝
 * A鏉嗕笂鏈塏涓┛瀛斿渾鐩橈紙浠庡皬鍒板ぇ缂栧彿1~N锛夛紝鐩樼殑灏哄鐢变笅鍒颁笂渚濇鍙樺皬銆? * 瑕佹眰鎸夎鍒欏皢鎵€鏈夊渾鐩樹粠A绉昏嚦C鏉嗭細
 *   - 姣忔鍙兘绉诲姩涓€涓渾鐩? *   - 澶х洏涓嶈兘鍙犲湪灏忕洏涓婇潰
 * 杈撳叆锛氭暣鏁癗鍜屼笁涓崟瀛楃锛堝垎鍒〃绀轰笁涓潌瀛愮殑缂栧彿锛? * 杈撳嚭锛氭瘡涓€姝ョЩ鍔ㄧ洏瀛愮殑璁板綍锛屾牸寮忎负 缂栧彿:璧峰鏉?>鐩爣鏉? *-----棰樼洰鍒嗘瀽-----*/
#include<iostream>
using namespace std;

/*-----绉诲姩鍑芥暟-----*/
// 澶栨樉绉诲姩杩囩▼銆佽緭鍑哄崟姝ョЩ鍔ㄨ褰曪細灏嗙紪鍙蜂负n鐨勭洏瀛愪粠start鏉嗙Щ鍔ㄥ埌target鏉?void move(char start, char target, int n)
{
    cout << n << ":" << start << "->" << target << endl;
    return;
}

/*-----dfs鍑芥暟鍒嗘瀽-----*/
// dfs锛氬皢n涓洏瀛愪粠start鏉嗭紝鍊熷姪middle鏉嗭紝绉诲姩鍒皌arget鏉?// 閫掑綊绛栫暐锛氬皢n-1涓洏瀛愮殑瀛愰棶棰樺鎵樼粰閫掑綊锛岃嚜宸卞彧璐熻矗绉诲姩鏈€搴曚笅鐨勭n涓洏瀛?// 杩欎笌Link09锛堟眽璇哄I锛変笉鍚屼箣澶勫湪浜庯細鏉嗗瓙缂栧彿鐢辫緭鍏ユ寚瀹氳€岄潪鍥哄畾涓篈/B/C锛?// 涓旇緭鍑烘牸寮忓寘鍚洏瀛愮紪鍙?void dfs(int n, char start, char middle, char target)
{
    // 閫掑綊鍑哄彛锛氬彧鏈変竴涓洏瀛愭椂锛岀洿鎺ヤ粠start绉诲姩鍒皌arget锛堟棤闇€鍊熷姪middle锛?    if (n == 1)
    {
        move(start, target, n);
        return;
    }

    // 绗竴姝ワ細鎶婁笂闈-1涓洏瀛愪粠start绉诲姩鍒癿iddle锛堝€熷姪target浣滀负涓存椂鏉嗭級
    dfs(n - 1, start, target, middle);

    // 绗簩姝ワ細鎶婃渶澶х殑绗琻涓洏瀛愮洿鎺ヤ粠start绉诲姩鍒皌arget
    move(start, target, n);

    // 绗笁姝ワ細鎶妌-1涓洏瀛愪粠middle绉诲姩鍒皌arget锛堝€熷姪start浣滀负涓存椂鏉嗭級
    dfs(n - 1, middle, start, target);

    return;
}

int main()
{
    int n;
    char a, b, c;
    cin >> n >> a >> b >> c;    // 璇诲叆鐩樺瓙鏁板拰涓変釜鏉嗗瓙鐨勭紪鍙?    dfs(n, a, b, c);            // 灏唍涓洏瀛愪粠a鍊熷姪b绉诲埌c
    return 0;
}