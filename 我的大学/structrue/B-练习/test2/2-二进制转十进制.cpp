#include <cstdio>
#include <cstdlib>

typedef int ElemType;
#define STACKSIZE 100
#define INCREASEMENTSTACK 10
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2
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

/*基于栈的顺序存储结构的判空操作*/
bool EmptyStack(const stackList& stk) {
    if (stk.top == stk.base)
        return false;
    else
        return true;
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

int main()
{
    stackList stk;
    InitStack(stk);
    printf("input the number you want to convert: ");
    char ch;
    while (scanf("%c", &ch) && ch != '\n')
        pushStack(stk, ch - '0');
    int num_D  = 0;
    int weight = 1;
    while (EmptyStack(stk)) {
        int elem;
        getTop(stk, elem);
        num_D += elem * weight;
        weight *= 2;
        popStack(stk);
    }
    printf("%d\n", num_D);
    return 0;
}
