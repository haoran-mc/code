#include <cstdio>
#include <ctime>
int main() {
    int C1 = clock();

    //程序<++>
    /*
     *int A;
     *for (int i = 0; i < 100; i++)
     *    scanf("%d", &A);
     *    std::cin >> A;
     */

    int C2 = clock();
    /*
     *printf("%d\n", C1);
     *printf("%d\n", C2);
     *printf("%d\n", CLK_TCK);
     */
    printf("%.3f\n", (double)(C2 - C1) / CLK_TCK);
    return 0;
}
