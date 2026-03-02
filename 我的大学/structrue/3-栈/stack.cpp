/*栈的顺序存储结构*/
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
void EmptyStack(const stackList& stk) {
    if (stk.top == stk.base)
        printf("empty!\n");
    else
        printf("not empty!\n");
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
    for (int i = 0; i < 10; ++i)
        pushStack(stk, rand()%100);
    EmptyStack(stk);
    int real;
    getTop(stk, real);
    printf("the top of stack is %d\n", real);

    //-------------------------------
    while (stk.top != stk.base)
        printf("pop all of the number in stack: %d\n", popStack(stk));

    return 0;
}
