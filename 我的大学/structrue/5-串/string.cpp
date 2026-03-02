/*
 * strcat
 * strcmp
 * strcpy
 * strlen
 * strupr
 */

#include <cstdio>

#define STRINGSIZE 100
#define INCREASEMENTSTRING 10
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2

/*基于串操作的串的求长度操作*/
int stringLen(const char* str) {
    int len = 0;
    while (*str != '\0') {
        ++str;
        ++len;
    }
    return len;
}

/*基于串操作的串的拼接操作*/
char* stringCat(char* str1, char* str2) {
    char* Address = str1;
    while (*str1 != '\0')
        ++str1;

    while (*str2 != '\0') {
        *str1 = *str2;
        ++str1;
        ++str2;
    }
    *str1 = '\0';
    return Address;
}

/*基于串操作的串的比较函数*/
int stringCmp(const char* str1, char* str2) {
    while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0') {
        ++str1;
        ++str2;
    }
    if (*str1 > *str2)
        return 1;
    else if (*str1 < *str2)
        return -1;
    else
        return 0;
}

/*基于串操作的串的大写转换函数*/
char* stringUpr(char* str) {
    char upr[STRINGSIZE];
    char* Address = upr;
    char* ptr = upr;
    while (*str != '\0') {
        *ptr = *str;
        if (*ptr <= 'z' && *ptr >= 'a')
            *ptr -= 32;

        ++str;
        ++ptr;
    }
    *ptr = *str;
    return Address;
}

/*基于串操作的串的大写转换函数*/
char* stringLwr(char* str) {
    char lwr[STRINGSIZE];
    char* Address = lwr;
    char* ptr = lwr;
    while (*str != '\0') {
        *ptr = *str;
        if (*ptr <= 'Z' && *ptr >= 'A')
            *ptr += 32;

        ++str;
        ++ptr;
    }
    *ptr = *str;
    return Address;
}

/*基于串操作的串的判空操作*/
void EmptyString(const char* str) {
    if (*str == '\0')
        printf("The string is empty!\n");
    else
        printf("The string is not empty!\n");
}

/*基于串操作的串的清空操作*/
void ClearString(char* str) {
    *str = '\0';
}

int main()
{
    char str[STRINGSIZE] = "hello";
    char cmp[STRINGSIZE] = "world";

    char cat1[STRINGSIZE] = "hello";
    char cat2[STRINGSIZE] = "world";

    printf("The length of str is %d\n", stringLen(str));
    printf("The new str is \"%s\"\n", stringCat(cat1, cat2));

    switch(stringCmp(str, cmp)) {
        case -1:
            printf("%s is front of %s\n", str, cmp);
            break;
        case 0:
            printf("%s is equal of %s\n", str, cmp);
            break;
        case 1:
            printf("%s is behind of %s\n", str, cmp);
            break;
    }

    char tem[STRINGSIZE] = "HeLLo WorlD!";
    printf("%s -> %s\n", tem, stringUpr(tem));
    printf("%s -> %s\n", tem, stringLwr(tem));
    return 0;
}
