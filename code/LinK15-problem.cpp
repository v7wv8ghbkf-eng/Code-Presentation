#include<iostream>
using namespace std;

// 鍔熻兘鏄緭鍑猴細鍓╀綑n涓彴闃舵湁鍑犵璧版硶
int dfs(int n)
{
    if(n == 0 || n == 1) return 1;
    if(n == 2) return 2;

    /*
    鍏跺疄灏辨槸锛?    int cur = dfs(n - 1) + dfs(n - 2);
    return cur;
    */
   // 鍓╀綑n涓彴闃剁殑璧版硶鍙栧喅浜庝笂涓€姝ユ槸鎬庝箞璧扮殑
   // 涓婁竴姝ヨ涔堟槸涓€绾у彴闃惰法涓婂幓銆佽涔堟槸涓ょ骇鍙伴樁璺ㄤ笂鍘伙紱鍒嗗埆鍓╀綑n - 1 / n - 2 绾у彴闃?   // 杩欓噷鐨勪换鍔″垎閰嶄篃鏄粠鏍归€掑綊鍒板彾瀛愬啀鍔犳€诲洖鏉?    return dfs(n - 1) + dfs(n - 2);
}

int main()
{
    int N;
    cin >> N;
    cout << dfs(N) << endl;
}