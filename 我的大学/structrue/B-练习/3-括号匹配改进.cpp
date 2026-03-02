#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef char ElemType;
const int maxn = 100;
#define STACKSIZE 100
#define INCREASEMENTSTACK 10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBILE -1
#define OVERFLOW -2
struct stackList {
    ElemType* base;
    ElemType* top;
    int stackSize;
};

/*基于顺序存储结构的栈的初始化操作*/
void InitStack(stackList& stk) {
    stk.base = (ElemType*)malloc(STACKSIZE*sizeof(ElemType));
    if (stk.base == NULL)
        exit(OVERFLOW);
    stk.top = stk.base;
    stk.stackSize = STACKSIZE;
}

/*基于栈的顺序存储结构的判空操作*/
bool EmptyStack(const stackList& stk) {
    if (stk.top == stk.base)
        return true;
    else
        return false;
}

/*基于顺序存储结构的栈的入栈操作*/
void pushStack(stackList& stk, ElemType elem) {
    if (stk.top - stk.base >= STACKSIZE) {
        ElemType* newbase = (ElemType*)realloc(stk.base, (STACKSIZE + INCREASEMENTSTACK)*sizeof(ElemType));
        if (newbase == NULL)
            exit(OVERFLOW);
        stk.base = newbase;
        stk.top  = stk.base + STACKSIZE;
        stk.stackSize += INCREASEMENTSTACK;
    }
    *stk.top = elem;
    stk.top++;
}

/*基于栈的顺序存储结构的取栈顶元素的操作*/
void getTop(const stackList& stk, ElemType& elem) {
    if (stk.top == stk.base)
        exit(OVERFLOW);
    elem = *(stk.top - 1);
}

/*基于栈的顺序存储结构的出栈操作*/
ElemType popStack(stackList& stk) {
    ElemType elem;
    if (stk.top == stk.base)
        exit(OVERFLOW);
    elem = *(--stk.top);
    return elem;
}

void match(stackList &stk, char input[]) {
    char elem;
    bool flag = true;
    int left  = 0;
    int right = 0;
    for (int i = 0; i < (int)strlen(input); ++i) {
        if (input[i] == '{' || input[i] == '[' || input[i] == '(') {
            pushStack(stk, input[i]);
            ++left;
        }
        else if (input[i] == '}') {
            ++right;
            getTop(stk, elem);
            if (elem != '{')
                flag = false;
            popStack(stk);
        }
        else if (input[i] == ']') {
            ++right;
            getTop(stk, elem);
            if (elem != '[')
                flag = false;
            popStack(stk);
        }
        else if (input[i] == ')') {
            ++right;
            getTop(stk, elem);
            if (elem != '(')
                flag = false;
            popStack(stk);
        }
        else
            continue;
    }
    if (EmptyStack(stk) == true && flag == true)
        printf("YES! You are right!\n");
    else if (left == right)
        printf("NO!  But the the number of left brackets equal to the right brackets!\n");
    else if (left > right)
        printf("NO!  The left brackets are more than right brackets!\n");
    else
        printf("NO!  The right brackets are more than left brackets!\n");
}

int main()
{
    stackList stk;
    InitStack(stk);
    char test[10][maxn] = {
        "{[(x)(x)]}",
        "{[x][x][x]}",
        "{([[x]])([{[x]}])}",
        "{([x][x])}",
        "{x}{x}{x}{x}",
        "{(((((}",
        "{(x)(x)(x)",
        "[[[x]]])",
        "{(}){}[}{]",
        "[)}{(}{}",
    };
    for (int i = 0; i < 10; ++i)
        match(stk, test[i]);

    return 0;
}
