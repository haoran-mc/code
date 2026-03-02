#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e7 + 5;
char str[maxn];

int main() {
    scanf("%s", str);
    if (str[0] == '-') {
        printf("%c", str[0]);
    }

    int E_pos = 0; // expo_pos = E_pos + 1
    for (int i = 1; i < strlen(str); i++) {
        if (str[i] == 'E') {
            E_pos = i;
            break;
        }
    }

    // 指数部分的十进制表示
    int expo = 0;
    for (int i = E_pos + 2; i < strlen(str); i++) {
        expo *= 10;
        expo += str[i] - '0';
    }

    if (str[E_pos + 1] == '+') {
        printf("%c", str[1]);

        if (expo >= E_pos - 3) { // 不需要保留小数点
            for (int i = 3; i < E_pos; i++) {
                printf("%c", str[i]);
            }
            int zero_cnt = expo - (E_pos - 3); // 应该补多少个零
            for (int i = 0; i < zero_cnt; i++) {
                printf("0");
            }
        } else {
            for (int i = 3; i < expo + 3; i++) {
                printf("%c", str[i]);
            }
            printf(".");
            for (int i = expo + 3; i < E_pos; i++) {
                printf("%c", str[i]);
            }
        }
    } else {
        if (expo == 0) { // 直接原样输出就行
            for (int i = 1; i < E_pos; i++) {
                printf("%c", str[i]);
            }
        } else { // 需要前补零
            printf("0.");
            expo--;
            for (int i = 0; i < expo; i++) {
                printf("0");
            }
            for (int i = 1; i < E_pos; i++) {
                if (str[i] != '.') {
                    printf("%c", str[i]);
                }
            }
        }
    }

    printf("\n");
    return 0;
}
