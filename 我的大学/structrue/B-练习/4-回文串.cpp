#include <cstdio>
#define STRINGSIZE 100

/*基于串操作的串的求长度操作*/
int stringLen(const char* str) {
    int len = 0;
    while (*str != '\0') {
        ++str;
        ++len;
    }
    return len;
}

bool judge(const char* str) {
    int len = stringLen(str)-1;
    int ptr = 0;
    bool flag = true;
    while (ptr < len) {
        if (str[ptr] != str[len])
            flag = false;

        ++ptr;
        --len;
    }
    return flag;
}

int main()
{
    char str[STRINGSIZE];
    scanf("%s", str);
    if (judge(str) == true)
        printf("It is a palindrome string\n");
    else
        printf("It is not a palindrome string\n");
    return 0;
}
