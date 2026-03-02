#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix_table(char pattern[], int prefix[]) {
    int n = strlen(pattern);
    int len = 0;
    prefix[0] = 0;

    int i = 1;
    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            prefix[i] = len;
            i++;
        }
        else {
            if (len > 0)
                len = prefix[len - 1];

            else {
                prefix[i] = 0;
                i++;
            }
        }
    }
}

void move_prefix_table(int prefix[], int n) {
    for (int i = n - 1; i > 0; i--)
        prefix[i] = prefix[i - 1];

    prefix[0] = -1;
}

void kmp_search(char pattern[], char text[]) {
    int n = strlen(pattern);
    int m = strlen(text);
    int* prefix = (int *)malloc(sizeof(int) * n);

    prefix_table(pattern, prefix);
    move_prefix_table(prefix, n);

    int j = 0;
    int i = 0;
    while (i < m) {
        if (j == n - 1 && pattern[j] == text[i]) {
            printf("Found pattern at %d\n", i - j);
            j = prefix[j];
        }

        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        else {
            j = prefix[j];
            if (j == -1) {
                j++;
                i++;
            }
        }
    }

    free(prefix);
}

int main()
{
    char pattern[] = "BBBB";
    char text[]    = "ABABBBBAAA";

    kmp_search(pattern, text);

    return 0;
}
