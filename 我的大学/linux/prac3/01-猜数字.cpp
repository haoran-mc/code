#include <cstdio>
#include <cstdlib>
#include <ctime>
#define MINNUM 1
#define MAXNUM 1000
using namespace std;

int main() {
    srand(time(0));
    int r = (rand() % MAXNUM) / MINNUM;
    int num;
    while (true) {
        printf("input a number(1, 1000):");
        scanf("%d", &num);
        if (num == r) {
            printf("Congratulations to guess!\n");
            break;
        } else if (num < r) {
            printf("less!\n");
        } else {
            printf("more!\n");
        }
    }
    return 0;
}
