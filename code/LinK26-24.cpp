/*-----棰樼洰鍒嗘瀽-----
 * 绠?4锛氱粰4涓?10鐨勯潪璐熸暣鏁帮紝鐢? - * /鍜屾嫭鍙疯兘鍚﹀噾鍑?4銆傚缁勬暟鎹紝浠?涓?缁撴潫銆? * 鏁板瓧鍙噸鎺掞紝闄ゆ硶鎸夊疄鏁伴櫎銆? *
 * 瑙ｆ硶锛欴FS鏋氫妇鎵€鏈夎繍绠楄繃绋嬨€備粠n涓暟涓€?涓仛6绉嶈繍绠?a+b,a-b,b-a,a*b,a/b,b/a)锛? *       缁撴灉涓庡墿浣欐暟缁勬垚鏂版暟缁勶紙瑙勬ā-1锛夛紝閫掑綊鍒板彧鍓?涓暟鍒ゆ柇鏄惁涓?4銆? *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <cmath>
using namespace std;
const double EPS = 1e-6;

bool dfs(double a[], int n) {
    if (n == 1) return fabs(a[0] - 24.0) < EPS;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            double b[4]; int m = 0;
            for (int k = 0; k < n; k++)
                if (k != i && k != j) b[m++] = a[k];  // 鍓╀綑鏁版斁鍏

            b[m] = a[i] + a[j]; if (dfs(b, m + 1)) return true;  // +
            b[m] = a[i] - a[j]; if (dfs(b, m + 1)) return true;  // a-b
            b[m] = a[i] * a[j]; if (dfs(b, m + 1)) return true;  // *
            if (fabs(a[j]) > EPS) { b[m] = a[i] / a[j]; if (dfs(b, m + 1)) return true; }  // a/b
        }
    }
    return false;
}

int main() {
    double a[4];
    while (cin >> a[0] >> a[1] >> a[2] >> a[3]) {
        if (a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0) break;
        cout << (dfs(a, 4) ? "YES" : "NO") << endl;
    }
    return 0;
}