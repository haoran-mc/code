/*----------------------------------------------------------------
 *
 *   文件名称：1019.cpp
 *   创建日期：2020年11月01日 ---- 11时53分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int A, int B) {
    return A > B;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int N;
    scanf("%d", &N);
    int one = 0;
    if (N % 1111 == 0) {
        printf("%04d - %04d = 0000\n", N, N);
        return 0;
    }
    do {
        int i = 4;
        int arr[4];
        while (i--) {
            arr[3-i] = N % 10;
            N /= 10;
        }
        sort(arr, arr+4, cmp);
        for (int i = 0; i < 4; ++i) {
            one = 10 * one + arr[i];
            N = 10 * N + arr[3-i];
        }
        printf("%04d - %04d = %04d\n", one, N, one-N);
        N = one - N;
        one = 0;
    } while (N != 6174);
    return 0;
}
