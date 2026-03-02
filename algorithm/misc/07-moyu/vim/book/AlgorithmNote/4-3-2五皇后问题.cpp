#include <stdio.h>
#include <math.h>

const int maxn = 11;
int n, p[maxn], hashTable[maxn] = { 0 };
int count = 0;

void generateP(int index) {
    if (index == n + 1) {
        count++;
        return ;
    }

    for (int x = 1; x <= n; x++) {
        if (hashTable[x] == 0) {
            bool flag = true;
            for (int pre = 1; pre < index; pre++) {
                if (abs(index - pre) == abs(x - p[pre])) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                p[index] = x;
                hashTable[x] = true;
                generateP(index + 1);
                hashTable[x] = false;
            }
        }
    }
}

int main()
{
    n = 8;
    generateP(1);
    printf("%d\n", count);
    return 0;
}
