#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
typedef char ElemType;
const int maxn = 100;
#define STACKSIZE  100
#define INCREASEMENTSTACK 10
#define TRUE         1
#define FALSE        0
#define OK           1
#define ERROR        0
#define INFEASIBILE -1
#define OVERFLOW    -2
#define bug printf("******\n");
struct stackList {
    ElemType* base;
    ElemType* top;
    int stackSize;
};

/*基于顺序存储结构的栈的初始化操作*/
void InitStack(stackList& stk) {
    stk.base = (ElemType *)malloc(STACKSIZE * sizeof(ElemType));
    if (stk.base == NULL)
        exit(OVERFLOW);
    stk.top = stk.base;
    stk.stackSize = STACKSIZE;
}

/*基于顺序存储结构的栈的入栈操作*/
void pushStack(stackList &stk, ElemType elem) {
    if (stk.top - stk.base >= STACKSIZE) {
        ElemType* newbase = (ElemType *)realloc(stk.base, (STACKSIZE + INCREASEMENTSTACK) * sizeof(ElemType));
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
        return true;
    else
        return false;
}

/*基于栈的顺序存储结构的取栈顶元素的操作*/
ElemType getTop(const stackList &stk) {
    if (stk.top == stk.base)
        exit(OVERFLOW);
    ElemType elem = *(stk.top - 1);
    return elem;
}

/*基于栈的顺序存储结构的出栈操作*/
ElemType popStack(stackList& stk) {
    ElemType elem;
    if (stk.top == stk.base)
        exit(OVERFLOW);
    elem = *(--stk.top);
    return elem;
}

/**/
char Precede(char op1, char op2) {
    if (op2 == '=') // = 优先级最低
        return '>';
    else if (op2 == '(')
        return '<';
    else if (op2 == ')' && op1 == '(')
        return '=';
    else if (op2 == ')')
        return '>';
    else if ((op2 == '/') && (op1 == '+' || op1 == '-' || op1 == '('))
        return '<';
    else if (op2 == '/')
        return '>';
    else if ((op2 == '*') && (op1 == '+' || op1 == '-' || op1 == '('))
        return '<';
    else if (op2 == '*')
        return '>';
    else if ((op2 == '+') && (op1 == '('))
        return '<';
    else if (op2 == '+')
        return '>';
    else if ((op2 == '-') && (op1 == '('))
        return '<';
    else if (op2 == '-')
        return '>';
    else
        return '0';
}

/**/
char Operate(char a, char theta, char b) {
    char res;
    if (theta == '+')
        res = char((int)(a-'0') + (int)(b-'0'));
    else if (theta == '-')
        res = char((int)(a-'0') - (int)(b-'0'));
    else if (theta == '*')
        res = char((int)(a-'0') * (int)(b-'0'));
    else if (theta == '/')
        res = char((int)(a-'0') / (int)(b-'0'));
    return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    stackList optr; //运算符
    stackList opnd; //操作数
    InitStack(optr);
    InitStack(opnd);
    char ch = getchar();
    while (!(ch == '=' && EmptyStack(optr) == true)) {
        if (ch <= '9' && ch >= '0') {
            pushStack(opnd, ch);
            ch = getchar();
        }
        else {
            if (EmptyStack(optr) == true) {
                pushStack(optr, ch);
                ch = getchar();
            }
            else {
                switch (Precede(getTop(optr), ch)) {
                    case '<':
                        pushStack(optr, ch);
                        ch = getchar();
                        break;
                    case '=':
                        popStack(optr);
                        ch = getchar();
                        break;
                    case '>':
                        char theta = popStack(optr);
                        char b     = popStack(opnd);
                        char a     = popStack(opnd);
                        pushStack(opnd, Operate(a, theta, b)+'0');
                        break;
                }
            }
        }
    }
    printf("%d\n", getTop(opnd)-'0');
    return 0;
}
