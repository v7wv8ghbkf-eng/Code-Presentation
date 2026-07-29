/*-----棰樼洰鍒嗘瀽-----*/
// 瀵绘壘鎵€鏈夊洓鍏冪粍 (a, b, c, d)锛屾弧瓒?a鲁 = b鲁 + c鲁 + d鲁
// 鍏朵腑 1 < a, b, c, d 鈮?N (N 鈮?100)锛屼笖 b 鈮?c 鈮?d
// 杈撳嚭鏍煎紡锛欳ube = a, Triple = (b,c,d)
// 鎸?a 鍗囧簭杈撳嚭锛宎 鐩稿悓鏃舵寜 b 鈫?c 鈫?d 浼樺厛绾ц緭鍑?
#include<iostream>
using namespace std;

/*-----绔嬫柟鍑芥暟-----*/
// 杩斿洖 x 鐨勭珛鏂瑰€硷紝鍐呰仈鍑忓皯鍑芥暟璋冪敤寮€閿€
inline int v(int x)
{
    return x * x * x;
}

int main()
{
    int N;
    cin >> N;

    // 鍥涢噸寰幆鏋氫妇 a, b, c, d
    // b 鈮?c 鈮?d 鐨勭害鏉熼€氳繃寰幆璧风偣淇濊瘉锛歜浠?寮€濮嬶紝c浠巄寮€濮嬶紝d浠巆寮€濮?    for (int a = 2; a <= N; a++)
    {
        for (int b = 2; b < a; b++)           // 纭繚涓ユ牸b < a,鍥犱负绔嬫柟鍜屼笉鍙兘绛変簬鏇村ぇ鐨勭珛鏂?        {
            // 纭繚b銆乧銆乨涓ユ牸鐨勯€掑鍏崇郴
            for (int c = b; c < a; c++)       // c 鈮?b锛屼笖 c < a
            {
                for (int d = c; d < a; d++)   // d 鈮?c锛屼笖 d < a
                {
                    if (v(a) == v(b) + v(c) + v(d))
                    {
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
                    }
                }
            }
        }
    }
    return 0;
}