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

//动态顺序存储结构
struct List {
    ElemType *elem;
    int length;
    int listSize;
};

//基于动态顺序存储结构的初始化引用写法
Status InitList (List &list) {
    list.elem = (ElemType *)malloc(LISTSIZE * sizeof(ElemType));
    if (list.elem == NULL)
        exit(OVERFLOW);

    list.length = 0;
    list.listSize = LISTSIZE;
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
    if (index < 0 || index > list.length+1)
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
    List orig;
    List oddf;
    List oddt;
    InitList(orig);
    InitList(oddf);
    InitList(oddt);

    printf("input the number of numbers: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &orig.elem[i]);
        ++orig.length;
    }

    int idx1 = 0;
    int idx2 = 0;
    for (int i = 0; i < n; ++i) {
        if (orig.elem[i] & 1)
            ListInsert(oddf, ++idx1, orig.elem[i]);
        else
            ListInsert(oddt, ++idx2, orig.elem[i]);
    }

    printf("print origin list: ");
    printf("\n\n");
    for (int i = 0; i < orig.length; ++i)
        printf("%d ", orig.elem[i]);
    printf("\n\n");

    printf("print odd list: \n");
    for (int i = 0; i < oddf.length; ++i)
        printf("%d ", oddf.elem[i]);
    printf("\n\n");

    printf("print even list: \n");
    for (int i = 0; i < oddt.length; ++i)
        printf("%d ", oddt.elem[i]);
    printf("\n\n");

    return 0;
}
