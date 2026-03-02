#include "head.h"
#include <stdio.h>
int scores[10000];

int main() {
    int num;
    printf("input the number of students:");
    scanf("%d", &num);
    printf("input the scores:\n");
    for(int i=0;i<num;i++){
        scanf("%d", &scores[i]);
    }
    Max(scores, num);
    Min(scores, num);
    Sum(scores, num);
    Avg(scores, num);
}
