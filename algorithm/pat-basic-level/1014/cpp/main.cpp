#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 60 + 5;
char str[4][maxn];
char week[8][5] = {"", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int day, hour, minu;

int main() {
    for (int i = 0; i < 4; i++) {
        scanf("%s", str[i]);
    }

    int len = min(strlen(str[0]), strlen(str[1]));
    int lastidx;

    // DAY
    for (int i = 0; i < len; i++) {
        if (str[0][i] == str[1][i]) {
            if ('A' <= str[0][i] && str[0][i] <= 'G') {
                day = str[0][i] - 'A' + 1;
                lastidx = i + 1;
                break;
            }
        }
    }

    // HOUR
    for (int i = lastidx; i < len; i++) {
        if (str[0][i] == str[1][i]) {
            if ('0' <= str[0][i] && str[0][i] <= '9') {
                hour = str[0][i] - '0';
                break;
            } else if ('A' <= str[0][i] && str[0][i] <= 'N') {
                hour = str[0][i] - 'A' + 10;
                break;
            }
        }
    }

    // MINU
    len = min(strlen(str[2]), strlen(str[3]));
    for (int i = 0; i < len; i++) {
        // 使用 ('A' <= str[2][i] && str[2][i] <= 'Z') || ('a' <= str[2][i] && str[2][i] <= 'z') 会失败
        // 使用 isalpha(str[2][i]) 会成功
        // 在法语、西班牙语等语言中，像 é, à, ñ 这样的字母，虽然它们不属于 a-z 或 A-Z 范围，但 isalpha 会将它们识别为字母字符。
        // 纯纯恶心人
        if (str[2][i] == str[3][i] && isalpha(str[2][i])) {
            minu = i;
            break;
        }
    }

    printf("%s %02d:%02d", week[day], hour, minu);
    return 0;
}
