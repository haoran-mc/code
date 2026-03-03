// 260303 08:03 Tue
#include <math.h>
#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    int data[n][2];
    int i;
    i = 0;
    double max;
    max = 0.00;

    while (i < n) {
        scanf("%d %d", &data[i][0], &data[i][1]);
        i++;
    }

    for (i = 0; i < n; i++) {
        if (max < sqrt((data[i][0] * data[i][0]) + data[i][1] * data[i][1])) {
            max = sqrt((data[i][0] * data[i][0]) + data[i][1] * data[i][1]);
        }
    }
    printf("%.2f\n", max);
    return 0;
}
