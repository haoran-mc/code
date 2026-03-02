#include <cstdio>
#include <cstdlib>

typedef int Status;
const int MAXSIZE = 255;
#define LISTSIZE  100
#define INCREAMENTLIST 10
#define ElemType  int
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2

//静态顺序存储结构
struct StaticList {
    ElemType elem[MAXSIZE];
    int length;
    int listSize;
};

//动态顺序存储结构
struct List {
    ElemType *elem;
    int length;
    int listSize;
};

//基于动态顺序存储结构的初始化引用写法
Status InitList1 (List &list) {
    list.elem = (ElemType *)malloc(LISTSIZE * sizeof(ElemType));
    if (list.elem == NULL)
        exit(OVERFLOW);

    list.length = 0;
    list.listSize = LISTSIZE;
    return OK;
}

//基于动态顺序存储结构的初始化指针写法
Status InitList2 (List *list) {
    (*list).elem = (ElemType *)malloc(LISTSIZE * sizeof(ElemType));
    if ((*list).elem == NULL)
        exit(OVERFLOW);

    (*list).length = 0;
    (*list).listSize = LISTSIZE;
    return OK;
}

//基于动态顺序存储结构的判空操作
void EmptyList(List list) {
    if (list.length == 0)
        printf("empty!\n");
    else
        printf("not empty!\n");
}

//基于动态顺序存储结构的求长度操作
int ListLength(List list) {
    return list.length;
}

//基于动态顺序存储结构的插入操作
void ListInsert(List &list, int index, int elem) {
    if (index < 0 || index >= list.length)
        printf("%d is not a legal position!\n", index);
    if (list.length == list.listSize) {
        auto newbase = (ElemType *)malloc((LISTSIZE + INCREAMENTLIST) * sizeof(ElemType));
        if (newbase == NULL)
            exit(OVERFLOW);
        list.elem = newbase;
        list.listSize += INCREAMENTLIST;
        list.length = list.listSize;
    }
    for (int i = list.length - 1; i >= index - 1; i--)
        list.elem[i+1] = list.elem[i];

    list.elem[index-1] = elem;
    list.length++;
}

//基于动态顺序存储结构的删除操作
void ListDelete(List &list, int index, int &Delete) {
    if (index < 0 || index >= list.length)
        printf("%d is not a legal position!\n", index);

    Delete = list.elem[index - 1];
    for (int i = index; i <list.length; i++)
        list.elem[i-1] = list.elem[i];

    list.length--;
}

int main()
{
    //创建一个头指针，并对这个动态顺序存储结构初始化
    List firstList;
    if (InitList1(firstList) == OK)
        printf("OK\n");

    //将创建的存储空间中存入十个不大于100的随机数
    for (int i = 0; i < 10; i++) {
        firstList.elem[i] = rand() % 100;
        firstList.length++;
    }
    //打印出随机数
    for (int i = 0; i < firstList.length; i++)
        printf("%d\n", firstList.elem[i]);

    //判断是否为空
    EmptyList(firstList);
    printf("List's length = %d\n", ListLength(firstList));

    //-------------------------------
    for (int i = 0; i < firstList.length; i++)
        printf("%d\n", firstList.elem[i]);
    EmptyList(firstList);
    printf("List's length = %d\n", ListLength(firstList));

    //-------------------------------
    int Delete;
    ListDelete(firstList, 5, Delete);
    for (int i = 0; i < firstList.length; i++)
        printf("%d\n", firstList.elem[i]);
    EmptyList(firstList);
    printf("The deleted element is %d\n", Delete);
    printf("List's length = %d\n", ListLength(firstList));

    return 0;
}
