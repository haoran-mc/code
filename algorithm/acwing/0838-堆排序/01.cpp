/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年08月08日 星期日 23时53分39秒
 *   题    目：AcWing 0838 堆排序
 *   算    法：堆
 *   描    述：输入n个数，从小到大输出前m小的数
 *      这里为什么下标从1开始呢？
 *      如果下标从1开始，left_node = 2 * node, right_node = 2 * node + 1
 *      如果下标从0开始，left_node = 2 * node + 1, right_node = 2 * node + 2
 *
 *      在初始化的阶段，由于i从n / 2开始，如果下标从1开始，i就一定是从
 *      后往前的第一个有子节点的节点(没有子节点自然不需要down)
 *      而从0开始的话，i = n / 2，得到的结果就可能是第一个叶子节点，虽然
 *      down一个叶子节点等于不操作，但是代码就不美了
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int he[maxn], tot;   // tot相当与栈中的tt(不用size是因为与Algorithm中关键字冲突)

void down(int u) {
    int minidx = u;  // 父亲与孩子中最小值的下标
    if (u * 2 <= tot && he[u * 2] < he[minidx])
        minidx = u * 2;
    if (u * 2 + 1 <= tot && he[u * 2 + 1] < he[minidx])
        minidx = u * 2 + 1;
    if (minidx != u) {
        swap(he[u], he[minidx]);
        down(minidx);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &he[i]);
    tot = n;

    /**
     * 初始化
     *   -------------------------------
     *  | - | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
     *   -------------------------------
     *                1
     *               / \
     *              /   \
     *             2     3   <--
     *            /|    / \
     *           / |   /   \
     *          4  5  6     7
     *
     *  从后往前地一个非叶子节点处开始down
     */
    for (int i = n / 2; i; --i)
        down(i);
    while (m--) {
        printf("%d ", he[1]);
        he[1] = he[tot--];
        down(1);
    }
    return 0;
}
