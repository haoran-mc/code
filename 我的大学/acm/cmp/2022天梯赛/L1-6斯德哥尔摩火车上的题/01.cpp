#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e4 + 5;
char str1[maxn], str2[maxn];
int res1[maxn], res2[maxn];
int idx1, idx2;

int main() {
    scanf("%s", str1);
    scanf("%s", str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int sta1 = 0, sta2 = 0;
    /*
    while (str1[sta1] == '0')
        sta1 ++ ;
    while (str2[sta2] == '0')
        sta2 ++ ;
    */
    idx1 = 0, idx2 = 0;
    for (int i = 1; i < len1; i ++ ) {
        int la  = str1[i - 1] - '0';
        int cur = str1[i] - '0';
        if (cur % 2 == la % 2) {
            res1[idx1] = max(cur, la);
            idx1 ++ ;
        }
    }
    for (int i = 1; i < len2; i ++ ) {
        int la  = str2[i - 1] - '0';
        int cur = str2[i] - '0';
        if (cur % 2 == la % 2) {
            res2[idx2] = max(cur, la);
            idx2 ++ ;
        }
    }
    bool is_same = false;
    if (idx1 == idx2) {
        is_same = true;
        for (int i = 0; i < idx1; i ++ )
            if (res1[i] != res2[i]) {
                is_same = false;
                break;
            }
    }
    if (!is_same) {
        for (int i = 0; i < idx1; i ++ )
            printf("%d", res1[i]);
        puts("");
    }
    for (int i = 0; i < idx2; i ++ )
        printf("%d", res2[i]);
    puts("");
    return 0;
}