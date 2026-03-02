#include <cstdio>
#include <cstdlib>

typedef int Status;
#define ElemType  int
#define MAXSIZE   255
#define LISTSIZE  100
#define INCREAMENTLIST 10
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2

//链式存储结构
typedef struct Node {
    ElemType data;
    Node *next;
}Node, *LinkList;

//基于链式存储结构的初始化
void InitList(LinkList &pNode) {
    pNode = (LinkList)malloc(sizeof(Node));
    if (pNode == NULL)
        exit(OVERFLOW);
    pNode -> data = OVERFLOW;
    pNode -> next = NULL;
}

//基于链式存储结构的插入操作(头插法)
void InsertList(LinkList &pNode, ElemType elem) {
    LinkList node = (LinkList)malloc(sizeof(Node));
    if (node == NULL)
        exit(OVERFLOW);
    node -> data = elem;
    node -> next = pNode -> next;
    pNode -> next = node;
}

//基于链式存储结构的插入操作(尾插法)
void InsertListEnd(const LinkList &pNode, ElemType elem) {
    LinkList Find = pNode;
    if (Find == NULL)
        exit(OVERFLOW);
    while (Find -> next != NULL)
        Find = Find -> next;

    Find -> next = (LinkList)malloc(sizeof(Node));
    Find = Find -> next;
    Find -> data = elem;
    Find -> next = NULL;
}

//基于链式存储结构的插入操作(在某个位置之前插入)
void InsertListMid(const LinkList &pNode, int position, ElemType elem) {
    if (pNode == NULL)
        exit(OVERFLOW);

    LinkList Find = pNode;
    int i = 0;
    //是1还是2
    while (i < position-1) {
        if (Find -> next == NULL)
            exit(OVERFLOW);
        i++;
        Find = Find -> next;
    }
    LinkList node = (LinkList)malloc(sizeof(Node));
    node -> data = elem;
    node -> next = Find -> next -> next;
    Find -> next -> next = node;
}

//基于链式存储结构的求长度操作
int ListLength(const LinkList &pNode) {
    LinkList trave = pNode -> next;
    int length = 0;
    while (trave != NULL) {
        ++length;
        trave = trave -> next;
    }
    return length;
}

void ListDelete(const LinkList &pNode, int position, int &Del) {
    int i = 0;
    LinkList Find = pNode;
    while (i < position) {
        if (Find -> next != NULL) {
            i++;
            Find = Find -> next;
        }
        else
            printf("This position is not exist!\n");
    }
    Del = Find -> next -> data;
    Find -> next = Find -> next -> next;
}

//输出链表data元素
void outputList(const LinkList &pNode) {
    LinkList print = pNode -> next;
    while (print != NULL) {
        printf("%d ", print -> data);
        print = print -> next;
    }
}

/*合并两个有序链表*/
void unionList(const LinkList &list1, const LinkList &list2, LinkList &list3) {
    LinkList pNode1 = list1 -> next;
    LinkList pNode2 = list2 -> next;
    while (pNode1 != NULL && pNode2 != NULL) {
        if (pNode1 -> data <= pNode2 -> data) {
            InsertListEnd(list3, pNode1 -> data);
            pNode1 = pNode1 -> next;
        }
        else {
            InsertListEnd(list3, pNode2 -> data);
            pNode2 = pNode2 -> next;
        }
    }

    while (pNode1 != NULL) {
        InsertListEnd(list3, pNode1 -> data);
        pNode1 = pNode1 -> next;
    }

    while (pNode2 != NULL) {
        InsertListEnd(list3, pNode2 -> data);
        pNode2 = pNode2 -> next;
    }
}

int main()
{
    LinkList pNode1;
    LinkList pNode2;
    InitList(pNode1);
    InitList(pNode2);

    LinkList pNode3;
    InitList(pNode3);

    int n;
    printf("input the number of number of list1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        InsertListEnd(pNode1, num);
    }

    printf("input the number of number of list2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        InsertListEnd(pNode2, num);
    }

    unionList(pNode1, pNode2, pNode3);
    outputList(pNode1);
    printf(" ------ the list1\n");
    outputList(pNode2);
    printf(" ------ the list2\n");
    outputList(pNode3);
    printf(" ------ the union list\n");

    return 0;
}
