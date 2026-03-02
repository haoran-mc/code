#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    int legalCnt = 0;
    double sum = 0;
    vector<string> vec;
    for (int a = 0; a < N; a++) {
        char str1[101], str2[101];
        cin >> str1;

        double val;
        sscanf(str1, "%lf", &val);
        sprintf(str2, "%.2lf", val);
        bool flag = true;
        for (int i = 0; i < strlen(str1); i++)
            if (str1[i] != str2[i])
                flag = false;

        if (flag && val >= -1000 && val <= 1000) {
            legalCnt++;
            sum += val;
        } else {
            printf("ERROR: %s is not a legal number\n", str1);
        }
    }
    if (legalCnt == 0)
        printf("The average of 0 numbers is Undefined\n");
    else if (legalCnt == 1)
        printf("The average of 1 number is %.2f\n", sum);
    else
        printf("The average of %d numbers is %.2f\n", legalCnt, sum / legalCnt);
    return 0;
}
