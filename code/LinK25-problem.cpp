/*-----题目分析-----
 * 拨钟问题：3×3共9个时钟，状态0/1/2/3（12点/3点/6点/9点）。
 * 9种移动各会拨动若干时钟90°。求最短移动序列使全部归0。
 *
 * 解法：枚举+推导。每种移动做4次=回到原点，所以次数∈{0,1,2,3}。
 *   只需枚举移动1,2,3各0~3次（4³=64种），然后根据时钟A的状态推导移动4的次数，
 *   根据B推导移动5……以此类推，最后验证所有时钟是否归0。
 *   取总次数最少的方案。
 *-----题目分析-----*/
#include <iostream>
#include <cstring>
using namespace std;

// 各移动影响的时钟（A~I用0~8表示）
const int moves[9][9] = {
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
        // 依A→B→C→D→G→E推出移动4~9
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

        // 验证全部9个时钟
        bool ok = true;
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
    // 按序号从小到大输出
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < best[i]; j++)
            cout << (i + 1) << " ";
    cout << endl;
    return 0;
}