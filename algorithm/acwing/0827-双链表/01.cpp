/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年07月28日 星期三 19时20分43秒
 *   题    目：AcWing 0827 双链表
 *   算    法：双链表
 *   描    述：删除第k个点，实际上传入的是k + 1, 因为idx下标从2开始
 *      第一行包含整数 M，表示操作次数。
 *      接下来 M 行，每行包含一个操作命令，操作命令可能为以下几种：
 *      - L x，表示在链表的最左端插入数 x。
 *      - R x，表示在链表的最右端插入数 x。
 *      - D k，表示将第 k 个插入的数删除。
 *      - IL k x，表示在第 k 个插入的数左侧插入一个数。
 *      - IR k x，表示在第 k 个插入的数右侧插入一个数。
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e5 + 5;
int e[maxn], l[maxn], r[maxn], idx;

void init() {
    // 0表示左端点，1表示右端点
    r[0] = 1, l[1] = 0;  // 初始时，0的右边是1,1的左边是0
    idx = 2;
}

/*
 *        |----| -------------> |----|
 *        |    |                |    |
 *        |----| <------------- |----|
 *             \                /
 *              \              / 
 *            3  \            / 2
 *   l[idx] = k   \          /  r[idx] = r[k]  
 *                 \        /    
 *                   |----| 
 *                   |    |  1
 *                   |----|  e[idx] = x
 *  在第k个点的右边插入x
 */
void add(int k, int x) {
    e[idx] = x;
    r[idx] = r[k];  // 新建的结点右结点是第k个结点右边的结点
    l[idx] = k;     // 新建的结点左结点是第k个结点
    l[r[k]] = idx;  // 第k个结点左侧的结点右侧是新建的结点
    r[k] = idx;     // 第k个结点右侧的结点是新建的结点
    ++idx;
}

void add_left(int k, int x) {
    add(l[k], x);
}

// 删除第k个结点
void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    int j = 0;
    int t; scanf("%d", &t);
    while (t--) {
        getchar();
        char ch; scanf("%c", &ch);
        int k, x;
        if (ch == 'L') {
            scanf("%d", &x);
            add(0, x);
        }
        else if (ch == 'R') {
            scanf("%d", &x);
            add_left(1, x);
        }
        else if (ch == 'D') {
            scanf("%d", &k);
            remove(k + 1);
        }
        else if (ch == 'I') {
            scanf("%c", &ch);
            if (ch == 'L') {
                scanf("%d %d", &k, &x);
                add_left(k + 1, x);
            }
            else if (ch == 'R') {
                scanf("%d %d", &k, &x);
                add(k + 1, x);
            }
        }
    }
    int i = 0;
    while (r[i] != 1) {
        i = r[i];
        printf("%d ", e[i]);
    }
    return 0;
}
