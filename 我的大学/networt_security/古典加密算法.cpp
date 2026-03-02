#include <cstdio>
#include <cstring>

void encode(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++ ) {
        if (('a' <= str[i] && str[i] <= 'y') || ('A' <= str[i] && str[i] <= 'Y')) {
            str[i] = (int)str[i] + 1;
        } else if (str[i] == 'z') {
            str[i] = 'a';
        } else if (str[i] == 'Z') {
            str[i] = 'A';
        }
    }
}

int main() {
    char str[80];   // 输入的加密串长度限制不超过 100
    scanf("%s", str);

    encode(str);
    printf("%s\n", str);
    return 0;
}
