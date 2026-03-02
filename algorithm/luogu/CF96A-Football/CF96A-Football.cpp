#include <cstdio>
#include <cstring>
int main() {
    char str[200];
    scanf("%s", str);
    for (int i = 0; i < (int)strlen(str); i++) {
        int sum0 = 0;
        int sum1 = 0;
        if (str[i] == '0') {
            for ( ; i < (int)strlen(str); i++) {
                if (str[i] == '0')
                    sum0++;
                else {
                    i--;
                    break;
                }

                if (sum0 == 7) {
                    printf("YES\n");
                    return 0;
                }
            }
        }
        else if (str[i] == '1') {
            for ( ; i < (int)strlen(str); i++) {
                if (str[i] == '1')
                    sum1++;
                else {
                    i--;
                    break;
                }
                if (sum1 == 7) {
                    printf("YES\n");
                    return 0;
                }
            }
        }
    }
    printf("NO\n");
    return 0;
}
