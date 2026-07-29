/*-----棰樼洰鍒嗘瀽-----*/
// 12鏋氱‖甯侊紙A-L锛夛紝鍏朵腑11鏋氱湡甯併€?鏋氬亣甯侊紙涓嶇煡杞婚噸锛?// 缁忚繃3娆＄О閲忥紝鏍规嵁澶╁钩缁撴灉鎵惧嚭鍋囧竵骞跺垽鏂叾杞婚噸
// 瑙ｆ硶锛氭灇涓炬硶鈥斺€斿姣忔灇纭竵鍋囪鍏朵负杞绘垨閲嶏紝楠岃瘉鏄惁婊¤冻涓夋绉伴噺缁撴灉

#include <iostream>
#include <string>
using namespace std;

/*-----绉伴噺鏁版嵁缁撴瀯-----*/
struct weigh
{
    string left;    // 澶╁钩宸﹁竟鏀剧疆鐨勭‖甯?    string right;   // 澶╁钩鍙宠竟鏀剧疆鐨勭‖甯?    string result;  // 澶╁钩缁撴灉锛歟ven(骞宠　) / up(鍙抽珮锛屽嵆宸﹂噸) / down(鍙充綆锛屽嵆宸﹁交)
};

/*-----check鍑芥暟鍒嗘瀽-----*/
// 鍋囪纭竵 coin 鏄亣甯侊紝涓?isLight 涓?true 琛ㄧず鍋囧竵杈冭交銆乫alse 琛ㄧず鍋囧竵杈冮噸
// 瀵逛笁娆＄О閲忕粨鏋滈€愪竴楠岃瘉锛屽鏋滃叏閮ㄧ鍚堝垯鍋囪鎴愮珛
bool check(char coin, bool isLight, weigh w[])
{
    for (int i = 0; i < 3; i++)
    {
        string l = w[i].left;
        string r = w[i].right;
        string res = w[i].result;

        // 缁熻宸﹀彸涓よ竟鐨?閲嶉噺"锛氬彧鍦ㄥ惈鏈夊亣璁惧亣甯佺殑閭ｄ竴渚ц繘琛屽姞鍑?        // 鐪熷竵閲嶉噺璁?锛屽亣甯佹牴鎹亣璁撅細杞讳负-1銆侀噸涓?1
        int leftWeight = 0, rightWeight = 0;

        // 杩欓噷鐩存帴閫氳繃鈥滄槸鍚﹀寘鍚亣甯佲€濆拰鈥滃亣璁剧殑鍋囧竵杞婚噸鈥濇潵鏀瑰彉鍏堝喅涓哄钩琛＄殑宸﹀彸閲嶉噺
        // 鍙互杩欎箞鎿嶄綔鏄洜涓哄彧鍖呭惈涓€鏋氬亣甯侊紝澶╁钩骞宠　涔熷彧鍜岃繖鏋氬亣甯佹湁鍏?        
        // 妫€鏌ュぉ骞冲乏渚ф槸鍚﹀寘鍚亣璁剧殑鍋囧竵
        for (char c : l)
        {
            if (c == coin)
            {
                // 鍋囧竵杞?鈫?宸︿晶閲嶉噺-1锛涘亣甯侀噸 鈫?宸︿晶閲嶉噺+1
                leftWeight += (isLight ? -1 : 1);
            }
        }

        // 妫€鏌ュぉ骞冲彸渚ф槸鍚﹀寘鍚亣璁剧殑鍋囧竵
        for (char c : r)
        {
            if (c == coin)
            {
                // 鍋囧竵鍦ㄥ彸渚э細杞?鈫?鍙充晶-1锛涢噸 鈫?鍙充晶+1
                rightWeight += (isLight ? -1 : 1);
            }
        }

        /*-----鏍规嵁澶╁钩缁撴灉楠岃瘉鍋囪-----*/
        // even锛氫袱杈归噸閲忓繀椤荤浉绛?        if (res == "even")
        {
            if (leftWeight != rightWeight)
                return false;
        }
        // up锛堝彸绔珮=宸︾閲嶏級锛氬乏渚ч噸閲忓繀椤?> 鍙充晶閲嶉噺
        else if (res == "up")
        {
            if (leftWeight <= rightWeight)
                return false;
        }
        // down锛堝彸绔綆=宸︾杞伙級锛氬乏渚ч噸閲忓繀椤?< 鍙充晶閲嶉噺
        else if (res == "down")
        {
            if (leftWeight >= rightWeight)
                return false;
        }
    }

    return true;    // 涓夋绉伴噺鍏ㄩ儴绗﹀悎鍋囪
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        weigh w[3];
        for (int i = 0; i < 3; i++)
        {
            cin >> w[i].left >> w[i].right >> w[i].result;
        }

        // 鏋氫妇12鏋氱‖甯?A-L锛屽姣忔灇鍒嗗埆鍋囪鍏朵负杞诲拰閲?        for (char c = 'A'; c <= 'L'; c++)
        {
            if (check(c, true, w))      // 鍋囪 c 鏄交鐨勫亣甯?            {
                cout << c << " is the counterfeit coin and it is light." << endl;
                break;
            }
            if (check(c, false, w))     // 鍋囪 c 鏄噸鐨勫亣甯?            {
                cout << c << " is the counterfeit coin and it is heavy." << endl;
                break;
            }
        }
    }

    return 0;
}