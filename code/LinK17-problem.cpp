/*-----棰樼洰鍒嗘瀽-----
 * 娉㈠叞琛ㄨ揪寮忥紙鍓嶇紑琛ㄨ揪寮忥級姹傚€硷細
 * 杩愮畻绗﹀啓鍦ㄦ搷浣滄暟涔嬪墠锛屽 "* + 2 3 4" 琛ㄧず (2+3)*4=20銆? * 杈撳叆涓虹┖鏍煎垎闅旂殑鍓嶇紑琛ㄨ揪寮忥紝鎿嶄綔鏁颁负娴偣鏁般€? *
 * 瑙ｆ硶锛氶€掑綊銆傚墠缂€琛ㄨ揪寮忓ぉ鐒堕€傚悎閫掑綊锛? *   璇诲叆涓€涓猼oken 鈫?鏄繍绠楃鍒欓€掑綊姹傚乏鍙虫搷浣滄暟骞惰繍绠楋紱
 *   鏄暟瀛楀垯鐩存帴杞琩ouble杩斿洖銆? *-----棰樼洰鍒嗘瀽-----*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/*-----dfs锛氶€掑綊姹傚€?----*/
double dfs() {
    string token; cin >> token;
    if (token == "+")      return dfs() + dfs();
    else if (token == "-") return dfs() - dfs();
    else if (token == "*") return dfs() * dfs();
    else if (token == "/") return dfs() / dfs();
    else                   return atof(token.c_str());  // 鏁板瓧
}

int main() {
    printf("%f\n", dfs());
    return 0;
}