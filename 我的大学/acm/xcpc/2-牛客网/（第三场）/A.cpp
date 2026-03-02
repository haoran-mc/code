//

#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    int clam = 0;
    int fish = 0;
    int t;
    int n;
    scanf("%d", &t);
    
    while(t--) {
        clam = 0;
        fish = 0;
        scanf("%d", &n);
        char stage[n];
        scanf("%s", stage);

        for (int i = 0; i < n; i++) {
            if (stage[i] == '0') {
                if (clam > 0) {
                    fish++;
                    clam--;
                }
            }
            else if (stage[i] == '1') {
                if (clam > 0) {
                    fish++;
                    clam--;
                }
                else {
                    clam++;
                }
            }
            else if (stage[i] == '2') {
                fish++;
            }
            else if (stage[i] == '3') {
                fish++;
            }
        }
        printf("%d\n", fish);
    }
    return 0;
}