#include <iostream>
#include <algorithm>
using namespace std;

// 纭澶ц嚧鐨勬暟缁勮寖鍥达紝闃叉鏁扮粍澶皬銆佽竟鐣屽お绱т粠鑰屽彂鐢熻秺鐣?const int N = 110;

// 鑺辩敓鍦扮殑琛屾暟鍜屽垪鏁?int row, col;
// w[i][j]绗琲琛岀j鍒楃殑鑺辩敓鏁伴噺锛沠[i][j]浠庡乏涓婅鍒拌揪(i,j)鑳芥憳鍒扮殑鏈€澶ц姳鐢熸暟
int w[N][N], f[N][N];

int main()
{
    // T缁勬祴璇曟暟鎹?    int T;
    cin >> T;
    while (T--)
    {
        // 杈撳叆鑺辩敓鍦扮殑琛屾暟鍜屽垪鏁?        cin >> row >> col;

        // 杈撳叆姣忔牚鑺辩敓鑻椾笂鐨勮姳鐢熸暟閲忥紝涓嬫爣浠?寮€濮?        for (int i = 1; i <= row; i++)
            for (int j = 1; j <= col; j++)
                cin >> w[i][j];

        /*----- 鐘舵€侀€掓帹锛氶€愯閫愬垪璁＄畻 -----*/
        // 鍙兘鍚戜笢(鍙?鎴栧悜鍗?涓?璧帮紝鎵€浠ワ細
        // 鍒拌揪(i,j)鍙兘浠庝笂杈?i-1,j)鎴栧乏杈?i,j-1)鏉?        // f[i][j] = max(涓婅竟鏉ョ殑鍊? 宸﹁竟鏉ョ殑鍊? + 褰撳墠浣嶇疆鑺辩敓鏁?        for(int x = 1; x <= row; x++)
        {
            for(int y = 1; y <= col; y++)
            {
                // f[x-1][y]鍜宖[x][y-1]鍦ㄨ竟鐣屽鑷姩涓?锛堝叏灞€鏁扮粍宸插垵濮嬪寲锛?                f[x][y] = max(f[x - 1][y], f[x][y - 1]) + w[x][y];
            }
        }

        // 鏈€缁堢瓟妗堬細璧板埌鍙充笅瑙?row,col)鏃舵憳鍒扮殑鏈€澶ц姳鐢熸€绘暟
        cout << f[row][col] << endl;
    }
    return 0;
}
