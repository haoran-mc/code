#include <stdio.h>
#include <math.h>


int calculate(int damage, int max_damage) {
    int si;
    si = 50 * ((double)damage / (double)max_damage);
    return ceil(si);
}

int main()
{
    int n;
    scanf("%d", &n);
    int damage[n];

    int max_damage;
    for (int i = 0; i < n; i++) {
        scanf("%d", &damage[i]);
        if (i == 0) {max_damage = damage[i];}
        else {
            if (damage[i] > max_damage)
                max_damage = damage[i];
        }
    }

    for (int i = 0; i < n; i++) {
        //计算si
        int si = calculate(damage[i], max_damage);

        for (int j = 0; j < si+2; j++) {
            if (j == 0 || j == si+1)
                printf("+");
            else
                printf("-");
        }
        printf("\n");

        for (int j = 0; j < si+2; j++) {
            if (j == 0 || j == si+1)
                printf("|");
            else {
                if (j == si) {
                    if (damage[i] == max_damage)
                        printf("*");
                }
                else
                    printf(" ");
            }
        }
        printf("%d\n", damage[i]);

        for (int j = 0; j < si+2; j++) {
            if (j == 0 || j == si+1)
                printf("+");
            else
                printf("-");
        }
        if (i != n-1)
            printf("\n");
    }

    return 0;
}
