/*-----棰樼洰鍒嗘瀽-----
 * 16脳16瀛楁瘝鏁扮嫭锛氬～鍏~P浣挎瘡琛屾瘡鍒楁瘡涓?脳4瀹牸鍐?6涓瓧姣嶅悇鍑虹幇涓€娆°€? * 杈撳叆涓?-'琛ㄧず绌烘牸锛屽缁勬暟鎹互绌鸿鍒嗛殧锛岃緭鍏ヨ嚦EOF銆? *
 * 瑙ｆ硶锛欴FS + 浜岃繘鍒剁姸鎬佸帇缂╋紙绫籐inK47浣嗘墿灞曞埌16脳16锛夈€? *   row/col/cell鐢?6浣嶄簩杩涘埗琛ㄧず鍙敤瀛楁瘝锛宭owbit鍙栦氦闆嗐€? *   浼樺寲鎼滅储椤哄簭锛氭瘡娆￠€夊彲閫夊瓧姣嶆渶灏戠殑绌烘牸銆? *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 16, M = 1 << N;               // M=65536
int row[N], col[N], cell[4][4];             // 浜岃繘鍒剁姸鎬?int ones[M], map[M];                        // 鎵撹〃
char str[N][N + 1];                         // 妫嬬洏锛堝惈'\0'锛?
inline int lowbit(int x) { return x & -x; }
inline int get(int x, int y) { return row[x] & col[y] & cell[x/4][y/4]; }

void init() {
    for (int i = 0; i < N; i++) map[1 << i] = i;
    for (int i = 0; i < M; i++) {
        ones[i] = 0;
        for (int j = i; j; j -= lowbit(j)) ones[i]++;
    }
    for (int i = 0; i < N; i++) row[i] = col[i] = M - 1;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) cell[i][j] = M - 1;
}

/*-----dfs锛氳繕鍓ヽnt涓┖鏍煎緟濉紝姣忔閫夊彲閫夊瓧姣嶆渶灏戠殑鏍煎瓙-----*/
bool dfs(int cnt) {
    if (!cnt) return true;                  // 鍏ㄩ儴濉畬
    int minv = 17, x = 0, y = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (str[i][j] == '-' && ones[get(i, j)] < minv)
                minv = ones[get(i, j)], x = i, y = j;

    for (int i = get(x, y); i; i -= lowbit(i)) {
        int t = map[lowbit(i)];
        row[x] -= 1 << t; col[y] -= 1 << t; cell[x/4][y/4] -= 1 << t;
        str[x][y] = 'A' + t;
        if (dfs(cnt - 1)) return true;
        row[x] += 1 << t; col[y] += 1 << t; cell[x/4][y/4] += 1 << t;
        str[x][y] = '-';
    }
    return false;
}

int main() {
    bool first = true;
    while (cin >> str[0]) {
        for (int i = 1; i < N; i++) cin >> str[i];
        init(); int cnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (str[i][j] != '-') {
                    int t = str[i][j] - 'A';
                    row[i] -= 1 << t; col[j] -= 1 << t; cell[i/4][j/4] -= 1 << t;
                } else cnt++;
        dfs(cnt);
        if (!first) cout << endl; first = false;
        for (int i = 0; i < N; i++) cout << str[i] << endl;
    }
    return 0;
}