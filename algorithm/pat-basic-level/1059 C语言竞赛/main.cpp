// 260227 15:02 Fri
#include <cstdio>
const int maxn = 1e5 + 1;
int listID[maxn];

bool isPrime(int num) {
    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;

    return true;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int ID;
        scanf("%d", &ID);
        listID[ID] = i;
    }

    int K;
    scanf("%d", &K);
    while (K--) {
        int ID;
        scanf("%d", &ID);
        if (listID[ID] == 0) {
            printf("%04d: Are you kidding?\n", ID);
            continue;
        } else if (listID[ID] == 1) {
            printf("%04d: Mystery Award\n", ID);
            listID[ID] = -1;
            continue;
        } else if (listID[ID] == -1) {
            printf("%04d: Checked\n", ID);
            listID[ID] = -1;
            continue;
        } else if (isPrime(listID[ID]) == true) {
            printf("%04d: Minion\n", ID);
            listID[ID] = -1;
            continue;
        } else {
            printf("%04d: Chocolate\n", ID);
            listID[ID] = -1;
            continue;
        }
    }
    return 0;
}
