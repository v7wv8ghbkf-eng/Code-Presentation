/*-----题目分析-----
 * 熄灯问题（Lights Out）：
 *   给定一个5行6列的01矩阵，0表示灯灭，1表示灯亮。
 *   每按下一个按钮，该按钮及其上下左右的灯状态取反（亮变灭，灭变亮）。
 *   每个按钮最多按一次（按两次等于没按），求一个按钮方案使得所有灯熄灭。
 *
 * 解题思路（逐行确定法）：
 *   关键性质：灯的状态只依赖其自身和上下左右的按钮。
 *   枚举第一行的所有2^6=64种按法，然后对每种枚举逐行确定：
 *     - 第i+1行的按钮必须让第i行的灯全部熄灭，
 *       即 press[i+1][j] = (puzzle[i][j] 在周围按钮影响后的状态)
 *     - 以此递推第2~5行，最后检查第5行是否全灭。
 *   第一个满足条件的方案即为答案（题目保证有唯一解）。
 *
 * 注意：每个输入用例有多组数据（T），需要依次输出每组答案。
 */
#include <iostream>
using namespace std;

int puzzle[5][6];   // 初始灯状态：0-灭，1-亮
int press[5][6];    // 按钮按下方案：1-按，0-不按

/*-----solve函数分析-----
 * 功能：枚举第一行所有64种按法，确定后续行，返回是否找到可行解。
 *
 * 算法流程：
 *   1. 枚举 firstRow ∈ [0, 63]，用二进制位表示第一行每列的按法
 *   2. 从第0行到第3行，根据当前灯的累积状态确定下一行的按钮
 *      —— 核心方程：press[i+1][j] 必须等于 puzzle[i][j] 在当前所有影响下的状态
 *   3. 检查第4行（最后一行）是否能全部熄灭
 *
 * 正确性：若第i行的按钮方案能保证前i-1行全灭，
 *   那么第i+1行的按钮由第i行的残余状态唯一确定，
 *   只需验证最后一行即可。
 */
bool solve() {
    // 枚举第一行的所有64种按法（2^6=64）
    for (int firstRow = 0; firstRow < 64; firstRow++) {
        // 根据firstRow的二进制位设置第一行的press
        for (int j = 0; j < 6; j++) {
            press[0][j] = (firstRow >> j) & 1;
        }

        /*-----逐行确定后续按钮-----
         * 对于第i行的每盏灯，计算它在已按下按钮影响下的当前状态（state），
         * 然后令 press[i+1][j] = state，使得经过第i+1行按钮影响后该灯熄灭。
         */
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 6; j++) {
                // 计算(i,j)位置的灯在当前所有已知按钮影响下的状态
                int state = puzzle[i][j];        // 初始状态
                state ^= press[i][j];            // 自身按钮
                if (j > 0) state ^= press[i][j-1];  // 左侧按钮
                if (j < 5) state ^= press[i][j+1];  // 右侧按钮
                if (i > 0) state ^= press[i-1][j];  // 上方按钮
                // 下方按钮 press[i+1][j] 必须恰好抵消此状态，才能使该灯熄灭
                press[i+1][j] = state;
            }
        }

        /*-----验证最后一行-----
         * 计算第4行每盏灯在所有按钮影响下的最终状态，必须全0。
         */
        bool ok = true;
        for (int j = 0; j < 6; j++) {
            int state = puzzle[4][j];
            state ^= press[4][j];            // 自身按钮
            if (j > 0) state ^= press[4][j-1];  // 左侧
            if (j < 5) state ^= press[4][j+1];  // 右侧
            state ^= press[3][j];            // 上方按钮（最后一行没有下方）
            if (state != 0) {
                ok = false;
                break;
            }
        }

        if (ok) return true;  // 找到可行方案
    }
    return false;  // 理论上题目保证有解，不会到达这里
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        // 读取5x6的初始灯状态
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                cin >> puzzle[i][j];
            }
        }
        solve();  // 计算按钮方案，结果存入press数组

        // 按格式输出
        cout << "PUZZLE #" << t << endl;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                cout << press[i][j];
                if (j < 5) cout << " ";
            }
            cout << " " << endl;  // 每行末尾带一个空格，符合题目输出格式
        }
    }
    return 0;
}
