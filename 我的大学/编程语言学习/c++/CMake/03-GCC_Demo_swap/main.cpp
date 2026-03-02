// #include "include/swap.h"
#include "swap.h"
#include <cstdio>
int main() {
    int i1 = 2;
    int i2 = 3;
    int i3 = 1;

    printf("i1 = %d   i2 = %d\n", i1, i2);
    swap(i1, i2);
    printf("i1 = %d   i2 = %d\n", i1, i2);
    return 0;
}
