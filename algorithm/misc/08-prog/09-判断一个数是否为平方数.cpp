#include <cstdio>
#include <cmath>
int main() {
    int n ;
    scanf("%d", &n) ;
    if (n == (int)sqrt(n) * (int)sqrt(n))
        printf("Yes!\n");
    else
        printf("No!\n");
    return 0;
}

