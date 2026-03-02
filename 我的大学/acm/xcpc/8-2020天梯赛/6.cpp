#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
#define bug printf("<------>\n");
char str[85];
int main()
{
    int fst = 0;
    int cnt = 0;
    int num = 0;
    char ch;
    while (scanf("%c", &ch) && ch != '.') {
        ++num;
        int i = 1;
        str[0] = ch;
        while (scanf("%c", &ch) && ch != 10) {
            str[i++] = ch;
        }
        str[i] = '\0';
        i = 0;
        char seek[15] = "chi1 huo3 guo1";
        seek[14] = '\0';
        while (str[i++] != '\0') {
            int k = i;
            int j = 0;
            while (str[k++] == seek[j++] || seek[j] == '\0')
                if (seek[j] == '\0') {
                    if (fst == 0)
                        fst = num;
                    ++cnt;
                    break;
                }
        }
    }
    printf("%d\n", num);
    fst ? printf("%d %d", fst, cnt) : printf("-_-#");
    return 0;
}
