#include <iostream>
using namespace std;

const int N = 110;
//全局变量初值为0
int parent[N];
int ranks[N];
bool isroot[N];

void initialize(int vertices) {
    for (int i = 0; i < vertices; i++) {
        parent[i] = -1;
        ranks[i]   =  0;
        isroot[i] = false;
    }
}

//递推
int find_root(int x) {
    while (parent[x] != -1) {
        x = parent[x];
    }
    return x;
}

//递归
int find_root(int x) {
    if (parent[x] == -1) return x;

    else {
        int x_root = find_root(parent[x]);
        return x_root;
    }
}

void union_vertices(int x, int y) {
    int x_root = find_root(x);
    int y_root = find_root(y);

    if (x_root == y_root) {
        return ;
    }
    else {
        if (ranks[x_root] > ranks[y_root]) 
            parent[y_root] = parent[x_root];

        else if (ranks[x_root] < ranks[y_root])
            parent[x_root] = parent[y_root];

        else {
            parent[x_root] = y_root;
            ranks[y_root]++;
        }
    }
}

int main()
{
    int vertices;
    int groups;
    scanf("%d%d", &vertices, &groups);

    initialize(vertices);

    for (int i = 0; i < groups; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        union_vertices(x, y);
    }

    for (int i = 0; i < groups; i++) {
        isroot[find_root(i)] = true;
    }

    int ans = 0;
    for (int i = 0; i < groups; i++) {
        ans += isroot[i];
    }
    printf("%d\n", ans);
    return 0;
}
