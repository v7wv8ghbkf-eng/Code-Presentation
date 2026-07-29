/*-----棰樼洰鍒嗘瀽-----
 * 鎷ㄩ挓闂锛?脳3鍏?涓椂閽燂紝鐘舵€?/1/2/3锛?2鐐?3鐐?6鐐?9鐐癸級銆? * 9绉嶇Щ鍔ㄥ悇浼氭嫧鍔ㄨ嫢骞叉椂閽?0掳銆傛眰鏈€鐭Щ鍔ㄥ簭鍒椾娇鍏ㄩ儴褰?銆? *
 * 瑙ｆ硶锛氭灇涓?鎺ㄥ銆傛瘡绉嶇Щ鍔ㄥ仛4娆?鍥炲埌鍘熺偣锛屾墍浠ユ鏁扳垐{0,1,2,3}銆? *   鍙渶鏋氫妇绉诲姩1,2,3鍚?~3娆★紙4鲁=64绉嶏級锛岀劧鍚庢牴鎹椂閽烝鐨勭姸鎬佹帹瀵肩Щ鍔?鐨勬鏁帮紝
 *   鏍规嵁B鎺ㄥ绉诲姩5鈥︹€︿互姝ょ被鎺紝鏈€鍚庨獙璇佹墍鏈夋椂閽熸槸鍚﹀綊0銆? *   鍙栨€绘鏁版渶灏戠殑鏂规銆? *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <cstring>
using namespace std;

// 鍚勭Щ鍔ㄥ奖鍝嶇殑鏃堕挓锛圓~I鐢?~8琛ㄧず锛?const int moves[9][9] = {
    {1,1,0,1,1,0,0,0,0}, {1,1,1,0,0,0,0,0,0}, {0,1,1,0,1,1,0,0,0},
    {1,0,0,1,0,0,1,0,0}, {0,1,0,1,1,1,0,1,0}, {0,0,1,0,0,1,0,0,1},
    {0,0,0,1,1,0,1,1,0}, {0,0,0,0,0,0,1,1,1}, {0,0,0,0,1,1,0,1,1}
};

int main() {
    int init[9], cnt[9], best[9] = {0}, bestCnt = 1e9;
    for (int i = 0; i < 9; i++) cin >> init[i];

    for (cnt[0] = 0; cnt[0] < 4; cnt[0]++)
    for (cnt[1] = 0; cnt[1] < 4; cnt[1]++)
    for (cnt[2] = 0; cnt[2] < 4; cnt[2]++) {
        // 渚滱鈫払鈫扖鈫扗鈫扜鈫扙鎺ㄥ嚭绉诲姩4~9
        int sumA = init[0]; for (int i = 0; i < 3; i++) sumA += cnt[i] * moves[i][0];
        cnt[3] = (4 - sumA % 4) % 4;

        int sumB = init[1]; for (int i = 0; i < 4; i++) sumB += cnt[i] * moves[i][1];
        cnt[4] = (4 - sumB % 4) % 4;

        int sumC = init[2]; for (int i = 0; i < 5; i++) sumC += cnt[i] * moves[i][2];
        cnt[5] = (4 - sumC % 4) % 4;

        int sumD = init[3]; for (int i = 0; i < 6; i++) sumD += cnt[i] * moves[i][3];
        cnt[6] = (4 - sumD % 4) % 4;

        int sumG = init[6]; for (int i = 0; i < 7; i++) sumG += cnt[i] * moves[i][6];
        cnt[7] = (4 - sumG % 4) % 4;

        int sumE = init[4]; for (int i = 0; i < 8; i++) sumE += cnt[i] * moves[i][4];
        cnt[8] = (4 - sumE % 4) % 4;

        // 楠岃瘉鍏ㄩ儴9涓椂閽?        bool ok = true;
        for (int c = 0; c < 9; c++) {
            int s = init[c];
            for (int i = 0; i < 9; i++) s += cnt[i] * moves[i][c];
            if (s % 4 != 0) { ok = false; break; }
        }
        if (ok) {
            int total = 0;
            for (int i = 0; i < 9; i++) total += cnt[i];
            if (total < bestCnt) {
                bestCnt = total;
                memcpy(best, cnt, sizeof(cnt));
            }
        }
    }
    // 鎸夊簭鍙蜂粠灏忓埌澶ц緭鍑?    for (int i = 0; i < 9; i++)
        for (int j = 0; j < best[i]; j++)
            cout << (i + 1) << " ";
    cout << endl;
    return 0;
}