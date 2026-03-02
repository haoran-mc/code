#include<iostream>
using namespace std;

int find0(char stage[], int i, int n) {
    int find = 0;
    for (; i < n; i++) {
        if (stage[i] == '1') 
            break;
        else if (stage[i] == '0') {
            find = 1;
            break;
        }
    }
    if (find == 1) 
        return 1;
    return 0;
}

int main()
{
    int fish;
    int clam;
    int t;
    int n;
    int sum0;
    int sum1;
    scanf("%d", &t);
    while(t--) {
        clam = 0;
        fish = 0;
        sum0 = 0;
        sum1 = 0;
        scanf("%d", &n);
        char stage[n+1];
        scanf("%s", stage);

        for (int i = 0; i < n; i++) {
            if (stage[i] == '1')
                sum1++;
            else if (stage[i] == '0')
                sum0++;
            else 
                fish++;
        }

        for (int i = 0; i < n; i++) {
            if (sum1 == 0) {
                break;
            }
            if (sum0 == 0) {
                fish = fish + (sum1 / 2);
                break;
            }
            else {
                if (stage[i] == '1') {
                    int find = find0(stage, i, n);

                    if (find == 1) {
                        sum1--;
                        fish++;
                    }
                    else {
                        sum1--;
                        sum0--;
                        fish++;
                    }
                }
                else if (stage[i] == '0') {
                    sum0--;
                }
            }
        }
        printf("%d\n", fish);
    }
    return 0;
}