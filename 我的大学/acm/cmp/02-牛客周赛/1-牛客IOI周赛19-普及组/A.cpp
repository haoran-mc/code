/*----------------------------------------------------------------
 *
 *   文件名称：A.cpp
 *   创建日期：2020年10月04日 ---- 19时34分
 *   题    目：nowcoder
 *   算    法：模拟
 *   描    述：优先三短一长
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        string A;
        string B;
        string C;
        string D;
        cin >> A;
        cin >> B;
        cin >> C;
        cin >> D;
        int Alen;
        int Blen;
        int Clen;
        int Dlen;
        Alen = A.length();
        Blen = B.length();
        Clen = C.length();
        Dlen = D.length();
        int maxlen = 0;
        int minlen = 0;
        maxlen = max(Alen, Blen);
        maxlen = max(maxlen, Clen);
        maxlen = max(maxlen, Dlen);
        minlen = min(Alen, Blen);
        minlen = min(minlen, Clen);
        minlen = min(minlen, Dlen);
        int maxflag = 0;
        int minflag = 0;
        string maxrecord;
        string minrecord;
        if (maxlen == Alen)
            maxflag++;
        if (maxlen == Blen)
            maxflag++;
        if (maxlen == Clen)
            maxflag++;
        if (maxlen == Dlen)
            maxflag++;

        if (minlen == Alen)
            minflag++;
        if (minlen == Blen)
            minflag++;
        if (minlen == Clen)
            minflag++;
        if (minlen == Dlen)
            minflag++;

        if (minflag == maxflag) {
            if (minflag == 1) {
                if (minlen == Alen) {
                    printf("A\n");
                    continue;
                }
                if (minlen == Blen) {
                    printf("B\n");
                    continue;
                }
                if (minlen == Clen) {
                    printf("C\n");
                    continue;
                }
                if (minlen == Dlen) {
                    printf("D\n");
                    continue;
                }
            }
            printf("C\n");
            continue;
        }
        else if (minflag < maxflag) {
            if (minlen == Alen) {
                printf("A\n");
                continue;
            }
            if (minlen == Blen) {
                printf("B\n");
                continue;
            }
            if (minlen == Clen) {
                printf("C\n");
                continue;
            }
            if (minlen == Dlen) {
                printf("D\n");
                continue;
            }
        }
        else {
            if (maxlen == Alen) {
                printf("A\n");
                continue;
            }
            if (maxlen == Blen) {
                printf("B\n");
                continue;
            }
            if (maxlen == Clen) {
                printf("C\n");
                continue;
            }
            if (maxlen == Dlen) {
                printf("D\n");
                continue;
            }
        }
    }
    return 0;
}
