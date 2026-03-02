#include <cstdio>
int n, k;

struct Node {
    Node* lchild;
    Node* rchild;
    int val;
};

Node* build_1(long long l, long long r) {
    Node* x = new(Node);
    if (l == r) {
    }
    else {
        long long mid = (l + r) / 2;
        x -> lchild = build_1(l, mid);
        x -> rchild = build_1(mid + 1, r);
    }
    return x;
}

Node* build_2(long long l, long long r) {
    Node* x = new(Node);
    if (r - l + 1 <= k) {
    }
    else {
        long long mid = (l + r) / 2;
        x -> lchild = build_2(l, mid);
        x -> rchild = build_2(mid + 1, r);
    }
    return x;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    return 0;
}
