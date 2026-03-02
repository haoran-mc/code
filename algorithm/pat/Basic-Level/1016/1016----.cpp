#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string strA;
    string strB;
    int DA;
    int DB;
    cin >> strA >> DA >> strB >> DB;
    int resA = 0;
    int resB = 0;
    int pos = 0;
    pos = strA.find((char)DA + '0', pos);
    while (pos != (int)string::npos) {
        resA = 10 * resA + DA;
        pos = strA.find((char)DA + '0', pos + 1);
    }
    pos = 0;
    pos = strB.find((char)DB + '0', pos);
    while (pos != (int)string::npos) {
        resB = 10 * resB + DB;
        pos = strB.find((char)DB + '0', pos + 1);
    }
    printf("%d\n", resA + resB);
    return 0;
}
