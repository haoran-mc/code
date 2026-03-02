#include <cstdio>
#include <cstdlib>

typedef int ElemType;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2
typedef struct Node {
    ElemType data;
    Node* next;
}Node, *linkList;

struct stackList {
    stackList* base;
    stackList* top;
    int stackSize;
};

void InitStack(stackList& stk) {
    //虽然是申请相同的空间，但是返回的指针类型不同
    //而返回的指针类型决定了这个空间的结构，也就决定了这些空间的使用方法
    //stackList* node1 = (stackList*)malloc(sizeof(Node));
    linkList node2 = (linkList)malloc(sizeof(1000));
    printf("sizeof%d\n", (int)sizeof(*node2));
    //node1 -> data = 1;
    node2 -> data = 2;
    printf("%d\n", node2 -> data);
}

void pushStack(stackList& stk, ElemType elem) {

}

ElemType getTop(stackList& stk) {
    return 1;
}

void popStack(stackList& stk) {

}

int main()
{
    stackList stk;
    InitStack(stk);
    for (int i = 0; i < 10; ++i)
        pushStack(stk, rand()%100);
    printf("the top of the stack is %d\n", getTop(stk));
    for (int i = 0; i < 10; ++i) {
        popStack(stk);
        printf("the top of the stack is %d\n", getTop(stk));
    }
    return 0;
}
