/*----------------------------------------------------------------
 *   
 *   文件名称：01.cpp
 *   创建日期：2021年07月26日 星期一 22时02分51秒
 *   题    目：Acwing 0826 单链表
 *   算    法：单链表
 *   描    述：因为数组下标是从0开始的，所以下标是k-1的数是第k个插入的
 *      第一行包含整数 M，表示操作次数
 *      接下来 M 行，每行包含一个操作命令，操作命令可能为以下几种
 *      - H x，表示向链表头插入一个数 x
 *      - D k，表示删除第 k 个插入的数后面的数（当 k 为 0 时，表示删除头结点）
 *      - I k x，表示在第 k 个插入的数后面插入一个数 x（此操作中 k 均大于 0）
 *    注意:题目中第 k 个插入的数并不是指当前链表的第 k 个数。例如操作过程中一共插入了 n 个数
 *    则按照插入的时间顺序，这 n 个数依次为：第 1 个插入的数，第 2 个插入的数，…第 n 个插入的数
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e5 + 5;

// head是头指针的下标
int head, e[maxn], ne[maxn];
// 也是相当于一个指针，一开始这个链表是空的，如果要往里面新建结点，就需要知道哪个结点是空的，idx指向的位置就是空的位置，将idx位置的结点填入数据之后，将idx向后移动一位，继续指向一个空的结点
int idx;   

void init() {
    head = -1; idx  = 0;
}

/**
 * head -> node1 -> node2 -> ... -> nodek
 *      ^
 *      |  要在这里插入一个结点(头结点处，头插法)
 */
void add_to_head(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

/**
 * head -> node1 -> node2 -> ... -> nodek -> ...
 *                                        ^
 *     在下标是k的结点后面插入一个结点    |
 *
 *  错了，不是上面这个操作，图画错了，不是第k个结点后面，是数组下标为k的后面
 *  没错，仔细体会，因为idx只有递增且每次加一，数组下标为k的结点就是第k个插入的
 */
void add(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

// 将下标为k的点后面的点删除
// 这里没有特判头节点删除的情况，题目中要是出现了remove(head)，需要在代码中判断
void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    init();
    int m; scanf("%d", &m);
    while (m--) {
        getchar();
        char ch; scanf("%c", &ch);
        int x, k;
        if (ch == 'H') {
            scanf("%d", &x);
            add_to_head(x);
        } 
        else if (ch == 'D') {
            scanf("%d", &k);
            if (k == 0) {
                head = ne[head];
                continue;
            }
            remove(k - 1);
        }
        else if (ch == 'I') {
            scanf("%d %d", &k, &x);
            add(k - 1, x);
        }
    }
    int i = head;
    while (i != -1) {
        printf("%d ", e[i]);
        i = ne[i];
    }
    return 0;
}
