#include<iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (; n != 1; cnt++){
        if ((n % 2) == false)
            n /= 2;

        else
            n = (3 * n + 1) / 2;
    }
    printf("%d\n", cnt);
    return 0;
}
