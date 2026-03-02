/*----------------------------------------------------------------
 *
 *   文件名称：segment-tree-struct.cpp
 *   创建日期：2021年03月07日 ---- 09时06分
 *   题    目：poj2182
 *   算    法：segment_tree
 *   描    述：算法竞赛从入门到进阶
 *
----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e5;
struct{
    int left;
    int right;
    int len;
} tree[4*maxn];
int pre[maxn];
int ans[maxn];

void buildTree(int left, int right, int node) {
    tree[node].left  = left;
    tree[node].right = right;
    tree[node].len = right - left + 1;
    if (left == right)
        return;
    buildTree(left, (left+right) >> 1, node << 1);
    buildTree(((left+right) >> 1)+1, right, (node << 1)+1);
}

int query(int node, int num) {
    --tree[node].len;
    if (tree[node].left == tree[node].right)
        return tree[node].left;
    if (tree[node << 1].len < num)
        return query((node << 1)+1, num-tree[node << 1].len);
    if (tree[node << 1].len >= num)
        return query(node << 1, num);
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    pre[1] = 0;
    for (int i = 2; i <= n; ++i)
        scanf("%d", &pre[i]);
    buildTree(1, n, 1);
    for (int i = n; i >= 1; --i)
        ans[i] = query(1, pre[i]+1);
    for (int i = 1; i <= n; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
