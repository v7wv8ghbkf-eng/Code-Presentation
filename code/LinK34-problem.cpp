/*-----棰樼洰鍒嗘瀽-----
 * 浜屽垎娉曟眰鏂圭▼鏍癸細f(x) = x鲁 - 5x虏 + 10x - 80 = 0锛岀簿纭埌9浣嶅皬鏁般€? * f(0)=-80<0, f(100)>0 鈫?鏍瑰湪[0,100]鍖洪棿銆傜洿鎺ヤ簩鍒嗐€? *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <iomanip>
using namespace std;

double f(double x) { return x*x*x - 5*x*x + 10*x - 80; }

int main() {
    double L = 0.0, R = 100.0;
    while (R - L > 1e-11) {         // 浜屽垎鍒拌冻澶熺簿搴?        double mid = (L + R) / 2.0;
        if (f(mid) > 0) R = mid; else L = mid;
    }
    cout << fixed << setprecision(9) << L << endl;
    return 0;
}