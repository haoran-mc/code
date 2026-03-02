#include <cstdio>
#include <stack>
using namespace std;
int getcul(int num1, int num2, char ch) {
    if (ch == '/')
        return num2 / num1;
    else if (ch == '*')
        return num1 * num2;
    else if (ch == '+')
        return num1 + num2;
    else
        return num2 - num1;
}
int main()
{
    stack<int>  stk1;
    stack<char> stk2;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        stk1.push(num);
    }
    for (int i = 0; i < n-1; ++i) {
        char ch;
        getchar();
        scanf("%c", &ch);
        stk2.push(ch);
    }
    for (int i = 0; i < n-1; ++i) {
        char ch = stk2.top();
        stk2.pop();
        int num1 = stk1.top();
        stk1.pop();
        int num2 = stk1.top();
        stk1.pop();
        if (ch == '/' && num1 == 0) {
            printf("ERROR: %d/0", num2);
            return 0;
        }
        //printf("%d %d %c\n", num1, num2, ch);
        int num3 = getcul(num1, num2, ch);
        //printf("%d\n", num3);
        stk1.push(num3);
    }
    printf("%d", stk1.top());
    return 0;
}
