#include <cstdio>
#include <cstring>
#include <stack>
#include <string>
const int maxn = 105;

char res[10][maxn] = {"ling", "yi",  "er", "san", "si",
                      "wu",   "liu", "qi", "ba",  "jiu"};

int main() {
    char str[maxn];
    scanf("%s", str);

    int sum = 0;
    for (int i = 0; i < strlen(str); i++) {
        int d = str[i] - '0';
        sum += d;
    }

    std::stack<int> stk;
    do {
        stk.push(sum % 10);
        sum /= 10;
    } while (sum > 0);

    while (!stk.empty()) {
        printf("%s", res[stk.top()]);
        stk.pop();
        if (!stk.empty()) {
            printf(" ");
        }
    }
    return 0;
}
