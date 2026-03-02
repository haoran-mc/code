#include <cstdio>
#include <cstdlib>

typedef int Status;
#define STRINGSIZE 100
#define INCREASEMENTSTRING 10
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2
#define bug printf("******\n");

struct Hstring{
    char* poin;
    int length;
};
char cat1[6] = "hello";
char cat2[8] = " world!";
char str3[STRINGSIZE] = "It's a fine day today. I'm going for an outing!";
char str4[STRINGSIZE] = "day";
char str5[STRINGSIZE] = "night";
Hstring text;
Hstring wrongStr;
Hstring replaceStr;

/*在堆分配存储结构上的字符串初始化操作*/
Status strAssign(Hstring &str, char* chars) {
    if (str.poin)
        free(str.poin);
    int len = 0;
    char* ptr = chars;
    for ( ; *ptr != '\0'; ++len, ++ptr);

    if (!len) {
        str.poin = NULL;
        str.length = 0;
    }
    else {
        if (!(str.poin = (char *)malloc(len * sizeof(char))))
            exit(OVERFLOW);

        for (int i = 0; i < len; ++i)
            str.poin[i] = chars[i];

        str.length = len;
    }
    return OK;
}

/*在堆分配存储结构上的字符串求长度操作*/
int strLength(const Hstring str) {
    return str.length;
}

/*在堆分配存储结构上的字符串拼接操作*/
Status stringCat(Hstring &str, Hstring str1, Hstring str2) {
    if (str.poin)
        free(str.poin);

    if (!(str.poin = (char *)malloc((str1.length + str2.length) * sizeof(char))))
        exit(OVERFLOW);

    char* ptr = str.poin;
    while (*str1.poin)
        *ptr++ = *str1.poin++;

    while (*str2.poin)
        *ptr++ = *str2.poin++;

    *ptr = '\0';
    str.length = str1.length + str2.length;
    return OK;
}

/*在堆分配存储结构上的字符串比较操作*/
int stringCmp(Hstring str1, Hstring str2) {
    while (*str1.poin == *str2.poin && *str1.poin != '\0' && *str2.poin != '\0') {
        ++str1.poin;
        ++str2.poin;
    }
    return *str1.poin - *str2.poin;
}

/*在堆分配存储结构上的字符串求子串操作*/
Status stringSub(Hstring &sub, Hstring str, int pos, int len) {
    if (pos < 0 || pos >= strLength(str) || len < 0 || len > str.length-pos)
        return OVERFLOW;

    if (sub.poin)
        free(sub.poin);
    if (!len) {
        sub.poin = NULL;
        sub.length = 0;
    }
    else {
        sub.poin = (char *)malloc((len+1) * sizeof(char));
        for (int i = 0; i < len; ++i)
            sub.poin[i] = str.poin[pos-1+i];

        sub.poin[len] = '\0';
        sub.length = len;
    }
    return OK;
}

/*在堆分配存储结构上的字符串转大写操作*/
Status stringUpr(Hstring &upr, Hstring str) {
    int len = str.length;
    if (upr.poin)
        free(upr.poin);
    if (!len) {
        upr.poin = NULL;
        upr.length = 0;
    }
    else {
        upr.poin = (char *)malloc(len * sizeof(char));
        char* ptr = upr.poin;
        while (*str.poin) {
            *upr.poin = *str.poin;
            if (*upr.poin <= 'z' && *upr.poin >= 'a')
                *upr.poin -= 32;

            ++str.poin;
            ++upr.poin;
        }
        *upr.poin = *str.poin;
        upr.poin = ptr;
    }
    return OK;
}

/*在堆分配存储结构上的字符串转小写操作*/
Status stringLwr(Hstring &lwr, Hstring str) {
    int len = str.length;
    if (lwr.poin)
        free(lwr.poin);
    if (!len) {
        lwr.poin = NULL;
        lwr.length = 0;
    }
    else {
        lwr.poin = (char *)malloc(len * sizeof(char));
        char* ptr = lwr.poin;
        while (*str.poin) {
            *lwr.poin = *str.poin;
            if (*lwr.poin <= 'Z' && *lwr.poin >= 'A')
                *lwr.poin += 32;

            ++str.poin;
            ++lwr.poin;
        }
        *lwr.poin = *str.poin;
        lwr.poin = ptr;
    }
    return OK;
}

/*在堆分配存储结构上的字符串kmp算法中求最长公共前后缀操作*/
void prefix_table(Hstring pattern, int prefix[]) {
    int len = strLength(pattern);
    prefix[0] = 0;
    int ptr   = 0;

    int i = 1;
    while (i < len) {
        if (pattern.poin[i] == pattern.poin[ptr]) {
            ++ptr;
            prefix[i] = ptr;
            ++i;
        }
        else {
            if (ptr > 0)
                ptr = prefix[ptr-1];
            else {
                prefix[i] = 0;
                ++i;
            }
        }
    }
}

/*在堆分配存储结构上的字符串kmp算法中移动最长公共前后缀操作*/
void move_prefix_table(int prefix[], int n) {
    for (int i = n-1; i > 0; --i)
        prefix[i] = prefix[i-1];

    prefix[0] = -1;
}

/*在堆分配存储结构上的字符串kmp算法查找子串操作*/
int kmp(Hstring text, Hstring pattern, int i) {
    int n = strLength(pattern);
    int m = strLength(text);
    int* prefix = (int *)malloc(sizeof(int) * n);

    prefix_table(pattern, prefix);
    move_prefix_table(prefix, n);

    int j = 0;
    while (i < m) {
        if (j == n-1 && text.poin[i] == pattern.poin[j]) {
            return i-j;
            j = prefix[j];
        }
        if (text.poin[i] == pattern.poin[j]) {
            ++i;
            ++j;
        }
        else {
            j = prefix[j];
            if (j == -1) {
                ++i;
                ++j;
            }
        }
    }
    return -1;
}

/*在堆分配存储结构上的字符串替换操作*/
Status strReplace(Hstring &str, Hstring text, Hstring wrongStr, Hstring replaceStr) {
    int i = 0;  // --> text
    int j = 0;  // --> str
    int len = strLength(text);
    if (str.poin)
        free(str.poin);
    if (!len) {
        str.poin = NULL;
        str.length = 0;
    }
    else {
        str.poin = (char *)malloc((strLength(text) / strLength(wrongStr) + 1) * strLength(replaceStr) *sizeof(char));
        while (i < len) {
            int idx = kmp(text, wrongStr, i);
            if (idx == -1)
                for ( ; i < len; ++i, ++j)
                    str.poin[j] = text.poin[i];
            else {
                for ( ; i < idx; ++i, ++j)
                    str.poin[j] = text.poin[i];

                i += strLength(wrongStr);
                for (int k = 0; k < strLength(replaceStr); ++k, ++j)
                    str.poin[j] = replaceStr.poin[k];
            }
        }
        str.poin[j] = '\0';
    }
    return OK;
}

int main()
{
    printf("----------------------------------\n");
    Hstring str;
    char chars[STRINGSIZE] = "hello";
    strAssign(str, chars);
    printf("str         = %s\n", str.poin);
    printf("str.length  = %d\n", strLength(str));

    //-----------------------------------------
    Hstring str1;
    Hstring str2;
    strAssign(str1, cat1);
    strAssign(str2, cat2);
    Hstring unionStr;
    stringCat(unionStr, str1, str2);
    printf("str1 + str2 = %s\n", unionStr.poin);

    //-----------------------------------------
    int cmp = stringCmp(str1, str2);
    if (cmp < 0)
        printf("str1 is front of str2\n");
    else if (cmp == 0)
        printf("str1 is equal of str2\n");
    else
        printf("str1 is behind of str2\n");
    printf("----------------------------------\n");

    //-----------------------------------------
    stringSub(str, unionStr, 3, 5);
    printf("the substring of unionStr is: \"%s\"\n", str.poin);

    //-----------------------------------------
    stringUpr(str, unionStr);
    printf("uppercase: %s\n", str.poin);

    //-----------------------------------------
    stringLwr(str, unionStr);
    printf("lowercase: %s\n", str.poin);

    //----------------------------------------
    printf("----------------------------------\n");
    strAssign(text, str3);
    strAssign(wrongStr, str4);
    strAssign(replaceStr, str5);
    strReplace(str, text, wrongStr, replaceStr);
    printf("string:\n%s\n", text.poin);
    printf("The replaced string is:\n%s\n", str.poin);
    printf("----------------------------------\n");
    return 0;
}

