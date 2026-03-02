/*----------------------------------------------------------------
 *
 *   文件名称：B-Yet-Another-Bookshelf.cpp
 *   创建日期：2020年10月20日 ---- 23时10分
 *   结束日期：2020年10月21日 ---- 23时42分
 *   题    目：codeforce
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>

const int maxn = 50;
int info[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        bool flag = false;
        int count = 0;
        int ans = 0;
        int places;
        scanf("%d", &places);
        for (int i = 0; i < places; i++) {
            scanf("%d", &info[i]);
            if (info[i] == 1)
                count++;
        }

        for (int i = 0; i < places; i++) {
            if (info[i] == 1 && flag == false) {
                flag = true;
                count--;
                continue;
            }
            if (flag == true && count > 0 && info[i] == 0)
                ans++;

            if (flag == true && count > 0 && info[i] == 1)
                count--;

            if (count == 0)
                break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
