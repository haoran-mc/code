#include<stdio.h>
#include<stdlib.h>
const int maxn = 1e6;
int parent[maxn];
int rank[maxn];

void init() {
    for (int i = 0; i < maxn; i++) {
        parent[i] = -1;
        rank[i] = 0;
    }
}

int find_root(int x) {
    int x_root = x;
    while (parent[x_root] != -1)
        x_root = parent[x_root];
    return x_root;
}

/* 1 - union successfully, 0 - union failed */
bool union_vertices(int x, int y) {
    int x_root = find_root(x);
    int y_root = find_root(y);

    if (x_root == y_root)
        return false;
    else {
        //parent[x_root] = y_root;
        if (rank[x_root] > rank[y_root])
            parent[y_root] = x_root;
        else if (rank[y_root] < rank[x_root])
            parent[x_root] = y_root;
        else {
            parent[x_root] = y_root;
            rank[y_root]++;
        }
        return true;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    init();
    for (int i = 0; i < n; ++i) {
        int x, y, e;
        scanf("%d %d %d", &x, &y, &e);
        if (e) {
            union_vertices(x, y);
            printf("YES");
        }
        else if (find_root(x) == find_root(y)) {
            printf("NO");
        }
    }
    return 0;
}
