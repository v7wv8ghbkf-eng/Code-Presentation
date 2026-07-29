#include<iostream>
using namespace std;

/*-----绉诲姩鍑芥暟move-----*/
// 澶栨樉绉诲姩杩囩▼锛岀敱鈥滄墍鍦ㄢ€濇煴瀛愮Щ鍔ㄥ埌鈥滅洰鏍団€濇煴瀛?
inline void move(char start, char target)
{
    cout << start << "->" << target << endl;
    return;
}

/*-----閫掑綊鍑芥暟鍒嗘瀽------*/
// hamoi锛氬皢n涓洏瀛愬€熷姪middle鐢眘tart绉诲姩鍒皌arget
// 鍥犱负鍙湁涓€涓洏瀛愮Щ鍔ㄥ彲浠ヤ笉鍊熷姪middle
// 姹夎帿濉旈棶棰樹竴娆″彧鑳界Щ鍔ㄤ竴涓洏瀛愶紝鎵€浠ヨ繖閲岀殑绉诲姩n涓洏瀛愭剰鍛崇潃绉诲姩涔嬪悗渚濈劧淇濇寔鑷笅鑰屼笂鐩樺瓙鍗婂緞鐨勫崌搴?
void hamoi(int n, char start, char middle, char target)
{
    // 濡傛灉鍙Щ鍔ㄤ竴涓洏瀛愶紝閭ｄ箞鐩存帴绉诲姩
    // 鎵€鏈夊鏉傞棶棰樻渶缁堥兘浼氬洖褰掑埌鏈€绠€鍗曠殑瀛愰棶棰橈紝鎵€浠ヨ繖涔熸槸閫掑綊鍑哄彛
    if(n == 1)
    {
        move(start, target);
        return;
    }

    // 棣栧厛锛屽皢n-1涓洏瀛愰€氳繃鏋佸叾澶嶆潅鐨勬柟寮忕Щ鍔ㄥ埌middle锛屼繚鎸佸崌搴?
    hamoi(n - 1, start, target, middle);
    // 鍏舵锛屽皢绗琻涓洏瀛愮Щ鍔ㄥ埌target浣滀负搴曞骇
    move(start, target);
    // 鏈€鍚庯紝灏唍-1涓洏瀛愮Щ鍔ㄥ埌target
    hamoi(n - 1, middle, start, target);
}

int main()
{
    int n;
    cin >> n;
    hamoi(n, 'A', 'B', 'C');
    return 0;
}