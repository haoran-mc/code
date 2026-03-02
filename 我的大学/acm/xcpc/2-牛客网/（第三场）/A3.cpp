//梁燕平的方法

#include<iostream>
using namespace std;
int main()
{
    int fish;
    int clam;
    int t;
    int n;
    int sum1;
    scanf("%d", &t);
    while(t--) {
        fish = 0;
        clam = 0;
        sum1 = 0;
        scanf("%d", &n);
        char stage[n+1];
        scanf("%s", stage);
        for (int i = 0; i < n; i++) {
            if (stage[i] == '0') {
                if (sum1 > 0) {
                    sum1--;
                    fish++;
                }
            }
            else if (stage[i] == '1') {
                sum1++;
            }
            else if (stage[i] == '2' || stage[i] == '3') {
                fish++;
            }
        }
        fish += (sum1 / 2);
        printf("%d\n", fish);
    }
    return 0;
}