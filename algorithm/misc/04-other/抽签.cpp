#include <cstdio>

const int M  =  50;
int main(){
    int n, m, k[M];
    int a, b, c, d;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &k[i]);

    bool f = false;
    for (a = 0; a < n; a++){
        for (b = 0; b < n; b++){
            for (c = 0; c < n; c++){
                for (d = 0; d < n; d++){
                    if (k[a]+k[b]+k[c]+k[d] == m){
                        f = true;
                        printf("Yes ");
                        printf("%d %d %d %d\n", k[a], k[b], k[c], k[d]);
                    }
                    else {
                        printf("No ");
                        printf("%d %d %d %d\n", k[a], k[b], k[c], k[d]);
                    }
                }
            }
        }
    }
    if (f == true)
        printf("hello");
    return 0;
}


