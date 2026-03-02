#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//计算前缀表
//计算前缀表是KMP算法的关键，这里需要三个参数
//pattern要寻找的字符串，前缀表prefix，字符串长度n
//好像不需要传入字符串长度n，也可以像下面一样使用strlen函数
void prefix_table(char pattern[], int prefix[], int n) {
    //第一个前缀表始终是0
    prefix[0] = 0;
    int len   = 0;

    //由于前缀表的第一个位置确定是0，所以从1开始
    int i = 1;
    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            prefix[i] = len;
            i++;
        }
        else {
            if (len > 0)
                len = prefix[len-1];
            else {
                prefix[i] = len;
                i++;
            }
        }
    }
}

//前缀表后移一位
void move_prefix_table(int prefix[], int n) {
    for (int i = n-1; i > 0; i--)
        prefix[i] = prefix[i-1];
    prefix[0] = -1;
}

//kmp搜索
//前两个函数在这里调用，主函数调用此函数
void kmp_search(char text[], char pattern[]) {
    int n = strlen(pattern);
    int m = strlen(text);
    int* prefix = (int *)malloc(sizeof(int) * n);

    prefix_table(pattern, prefix, n);
    move_prefix_table(prefix, n);

    // pattern[j] , len(pattern) = n
    // text[i]    , len(text)    = m

    int i = 0;
    int j = 0;
    while (i < m) {
        if (j == n-1 && pattern[j] == text[i]) {
            printf("Found pattern at %d\n", i - j);
            j = prefix[j];
        }

        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        else {
            j = prefix[j];
            if (j == -1) {
                i++;
                j++;
            }
        }
    }
}

int main() {
    char pattern[] = "ABABCABAA";
    char text[]    = "ABABABCABAABABAABAB";

    kmp_search(text, pattern);

    return 0;
}
