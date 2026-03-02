#include<iostream>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        if (n == 1) {
            printf("26\n");
        }
        else if (n == 2) {
            printf("676\n");
        }
        else if (n == 3) {
            printf("17400\n");
        }
        else {
            printf("15600\n");
        }
    }
    return 0;
}
