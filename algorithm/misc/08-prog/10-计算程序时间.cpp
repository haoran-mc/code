#include <cstdio>
#include <ctime>
int main() {
    clock_t start;
    clock_t end;
    start = clock();
    end   = clock();
    printf("time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
