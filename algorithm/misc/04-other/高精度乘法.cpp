#include <bits/stdc++.h>
using namespace std;

char a[2005], b[2005];
int aa[2005], bb[2005], cc[5000];

int main()
{
    int lenA, lenB, lenC;
    scanf("%s", a);
    scanf("%s", b);
    lenA = strlen(a);
    lenB = strlen(b);
    lenC = lenA + lenB + 1;
    for (int i = 0; i < lenA; i++)
        aa[i] = a[lenA-1-i] - '0';

    for (int j = 0; j < lenB; j++)
        bb[j] = b[lenB-1-j] - '0';

    for (int i = 0; i < lenA; i++) {
        for (int j = 0; j < lenB; j++) {
            cc[i+j]   += aa[i] * bb[j];
            cc[i+j+1] += cc[i+j] / 10;
            cc[i+j]    = cc[i+j] % 10;
        }
    }
    while (cc[lenC] == 0 && lenC > 0)
        lenC--;

    for (int i = lenC; i >= 0; i--)
        printf("%d", cc[i]);

    return 0;
}
