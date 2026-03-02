#include <cstdio>
#include <cmath>

const double eps = 1e-8; 

int main()
{
    int num = 100000;
    while (num--) {
        int sum = 0;
        int i   = 0;

        for (i = num + 1; i > 0; i--)
            sum += i * i;

        if (sqrt(sum) - (int)sqrt(sum) < eps)
            printf("%d\n", num + 1);
    }

    return 0;
}
