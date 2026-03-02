/*
 * n(数码宝贝个数) m(好朋友组数)
 * n1           n2
 * n1           n3
 * ...
 * n3           nm
 *
 * output:可分成的组数
 */

//压缩查找路径
#include<iostream>
using namespace std;

void initialize(int parent[], int vertices) {
    for (int i = 0; i < vertices; i++) {
        parent[i] = -1;
    }
}

//递推
int find_root1(int x, int parent[]) {
    int x_root = x;
    int ano_x = x;
    while (parent[x_root] != -1) {
        x_root = parent[x_root];
    }

    while (parent[ano_x] != -1) {
        int sho_x = ano_x;
        parent[ano_x] = x_root;
        ano_x = parent[sho_x];
    }
    return x_root;
}

//递归
//对于递归，参数需要根据条件不断变化
int find_root2(int x, int parent[]) {
    if (parent[x] == -1) return x;

    else {
        //这里的x_root始终不变，变化的是x
        int x_root = find_root2(parent[x], parent);
        parent[x] = x_root;
        return x_root;
    }
}

void union_vertices(int x, int y, int parent[]) {
    int x_root = find_root2(x, parent);
    int y_root = find_root2(y, parent);

    if (x_root != y_root) {
        parent[x_root] = y_root;
    }
}

int main()
{
    int vertices;
    int n;
    int baby[n][2];
    int parent[vertices];
    bool isroot[vertices];

    initialize(parent, vertices);
    for (int i = 0; i < vertices; i++) {
        isroot[i] = false;
    }

    int i = 0;
    while (n--) {
        scanf("%d%d", &baby[i][0], &baby[i][1]);
        union_vertices(baby[i][0], baby[i][1], parent);
        i++;
    }

    //点睛之笔
    for (int i = 1; i <= n; i++) {
        isroot[find_root1(i, parent)] = true;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += isroot[i];
    }
    printf("%d\n", ans);
    return 0;
}
