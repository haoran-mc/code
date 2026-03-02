#include<iostream>
#include<cstdlib>

#define VERTICES 6

void initialize(int parent[], int rank[]) {
    for (int i = 0; i < VERTICES; i++) {
        parent[i] = -1;
        rank[i]   = -1;
    }
}

int find_root(int x, int parent[]) {
    int x_root = x;
    while (parent[x_root] != -1) {
        x_root = parent[x_root];
    }
    return x_root;
}

int union_vertices(int x, int y, int parent[], int rank[]) {
    int x_root = find_root(x, parent);
    int y_root = find_root(y, parent);
    
    if (x_root == y_root) {
        return 0;
    }
    else {
        if(rank[x_root] > rank[y_root]) {
            parent[y_root] = x_root;
        }
        else if (rank[x_root] < rank[y_root]) {
            parent[x_root] = y_root;
        }
        else {
            parent[x_root] = y_root;
            rank[y_root]++;
        }
    }
}


int main()
{
    int parent[VERTICES] = {0};
    int rank[VERTICES] = {0};
    int edges[6][2] = {
        {0, 1}, {1, 2}, {1, 3},
        {2, 4}, {3, 4}, {2, 5}
    };
    
    initialize(parent, rank);
    for (int i = 0; i < 6; i++) {
        int x = edges[i][0];
        int y = edges[i][0];
        if (union_vertices(x, y, parent, rank) == 0) {
            printf("Cycle detected!\n");
            exit(0);
        }
    }
    printf("No cycle fond.\n");
    
    return 0;
}

