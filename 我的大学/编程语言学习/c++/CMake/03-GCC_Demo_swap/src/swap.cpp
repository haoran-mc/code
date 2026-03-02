// #include "../include/swap.h"
#include "swap.h"
#include <cstdio>

void swap(int &i1, int &i2) {
    int tmp = i1;
    i1 = i2;
    i2 = tmp;
}
