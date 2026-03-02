#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix_table(char pattern[], int prefix[], int n) {
    prefix[0] = 0;
    int len   = 0;

    int i = 1;
    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            prefix[i] = len;
            i++;
        }
        else {
            if (len > 0) {
                len = prefix[len-1];
            }
            else {
                prefix[i] = len;
                i++;
            }
        }
    }
}
