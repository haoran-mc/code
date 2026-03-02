#include<iostream>
//在vscode中注释下面此行头函数仍可运行
//但在其他编辑器或IDE中可能不行，所以不可省略
#include<cstdlib>
using namespace std;

//顶点数
#define VERTICES 6

void initialize(int parent[], int rank[]) {
    for (int i = 0; i < VERTICES; i++) {
        parent[i] = -1;
        rank[i] = -1;
    }
}

int find_root(int x, int parent[]) {
    int x_root = x;
//parent[] 中每个结点处存储的是父结点的
    while (parent[x_root] != -1) {
        x_root = parent[x_root];
    }
    return x_root;
}

/* 1 - union successfully, 0 - union failed */
int union_vertices(int x, int y, int parent[], int rank[]) {
    int x_root = find_root(x, parent);
    int y_root = find_root(y, parent);

    if (x_root == y_root) {
        return 0;
    }
    else {
        //parent[x_root] = y_root;
        if (rank[x_root] > rank[y_root]) {
            parent[y_root] = x_root;
        } 
        else if (rank[x_root] < rank[y_root]) {
            parent[x_root] = y_root;
        }
        else {
            parent[x_root] = y_root;
            rank[y_root]++;
        }
        return 1;
    }
}

int main()
{
    int parent[VERTICES] = {0};
    int rank[VERTICES] = {0};
    //这里 edges[6][2] 中的 6 不是顶点数 VERTICES
    //而是在这六个顶点间的六条连线
    int edges[6][2] = {
        {0, 1}, {1, 2}, {1, 3},
        {2, 4}, {3, 4}, {2, 5}
    };

    initialize(parent, rank);
    //这里 i < 6 中的 6 也是连线数
    for (int i = 0; i < 6; i++) {
    //提取出每条边的两个顶点
        int x = edges[i][0];
        int y = edges[i][1];
        if (union_vertices(x, y, parent, rank) == 0) {
            printf("Cycle detected!\n");
            exit(0);
        }
    }
    printf("No cycle fond.\n");

    return 0;
}
