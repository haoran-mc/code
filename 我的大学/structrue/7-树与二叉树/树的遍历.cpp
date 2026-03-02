#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;
#define maxn 100
typedef int Status;
#define STRINGSIZE 100
#define INCREASEMENTSTRING 10
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2

struct Node {
    char data;
    Node* left;
    Node* right;
    bool flag;
};
struct Tree {
    Node* root;
};

/*二叉树的前序遍历操作*/
void preorder(Node* node) {
    if (node != NULL) {
        printf("%c ", node -> data);
        preorder(node -> left);
        preorder(node -> right);
    }
}

/*二叉树的中序遍历操作*/
void inorder(Node* node) {
    if (node != NULL) {
        inorder(node -> left );
        printf("%c ", node -> data);
        inorder(node -> right);
    }
}

/*二叉树的后序遍历操作*/
void postorder(Node* node) {
    if (node != NULL) {
        postorder(node -> left );
        postorder(node -> right);
        printf("%c ", node -> data);
    }
}

/*求二叉树深度*/
int treeDepth(Node* node) {
    if (node == NULL)
        return 0;

    int leftDepth  = treeDepth(node -> left)  + 1;
    int rightDepth = treeDepth(node -> right) + 1;
    return leftDepth < rightDepth ? rightDepth : leftDepth;
}

/*求二叉树结点个数*/
int treeSumNode(Node* node) {
    if (node == NULL)
        return 0;

    int leftSum  = treeSumNode(node -> left);
    int rightSum = treeSumNode(node -> right);
    return leftSum + rightSum + 1;
}

/*求二叉树叶子结点个数*/
int treeSumLeftNode(Node* node) {
    if (node == NULL)
        return 0;

    int leftSum  = treeSumLeftNode(node -> left);
    int rightSum = treeSumLeftNode(node -> right);
    int sum = leftSum + rightSum;
    if (node -> left == NULL && node -> right == NULL)
        ++sum;
    return sum;
}

/*求二叉树结点所在层次*/
void searchLayer(Node* node, char value, int &depth, bool &flag) {
    if (node == NULL)
        return;

    if (node -> data == value)
        flag = true;

    if (!flag) ++depth;
    searchLayer(node -> left, value, depth, flag);
    searchLayer(node -> right, value, depth, flag);
    if (!flag) --depth;
}

/*依据先序遍历创建二叉树操作*/
Status creatBiTree(Node* &node) {
    char ch;
    scanf("%c", &ch);
    //getchar();
    /*如果输入为#，说明结点指向空*/
    if (ch == '#' || ch == '\0')
        node = NULL;
    else {
        if (!(node = (Node *)malloc(sizeof(Node))))
            exit(OVERFLOW);
        node -> data = ch;
        node -> flag = false;
        creatBiTree(node -> left);
        creatBiTree(node -> right);
    }
    return OK;
}

/*非递归先序遍历*/
void norePreorder(Tree T) {
    stack<Node> stk;
    Node *node = T.root;
    while (node || !stk.empty()) {
        while (node) {
            printf("%c ", node -> data);
            stk.push(*node);
            node = node -> left;
        }
        node = &stk.top();
        stk.pop();
        node = node -> right;
    }
}

/*非递归的中序遍历*/
void noreInorder1(Tree T) {
    stack<Node> stk;
    Node *node = T.root;
    while (node || !stk.empty()) {
        if (node) {
            stk.push(*node);
            node = node -> left;
        }
        else {
            node = &stk.top();
            stk.pop();
            printf("%c ", node -> data);
            node = node -> right;
        }
    }
}

/*非递归的中序遍历*/
void noreInorder2(Tree T) {
    stack<Node> stk;
    Node *node = T.root;
    while (node || !stk.empty()) {
        while (node) {
            stk.push(*node);
            node = node -> left;
        }
        node = &stk.top();
        stk.pop();
        printf("%c ", node -> data);
        node = node -> right;
    }
}

/*复原标志*/
void flagReback(Node* node) {
    if (node != NULL) {
        node -> flag = false;
        flagReback(node -> left);
        flagReback(node -> right);
    }
}

/*非递归后序遍历*/
void norePostorder(Tree T) {
    stack<Node> stk;
    Node *node = T.root;
    while (node || !stk.empty()) {
        while (node) {
            if (!(node -> flag))
                stk.push(*node);
            node -> flag = true;
            node = node -> left;
        }
        node = &stk.top();
        if ((!(node -> left) || (node -> left -> flag)) && ((!(node -> right) || (node -> right -> flag))))
            printf("%c ", node -> data),
            stk.pop();
        node = node -> right;
    }
    flagReback(T.root);
}

/*求二叉树从根节点到叶子结点的路径*/
stack<Node> getRoute(Tree T, char value) {
    stack<Node> stk;
    Node *node = T.root;
    while (node || !stk.empty()) {
        while (node) {
            if (!(node -> flag))
                stk.push(*node);
            node -> flag = true;
            node = node -> left;
        }
        node = &stk.top();
        if ((!(node -> left) || (node -> left -> flag)) && ((!(node -> right) || (node -> right -> flag)))) {
            if (node -> data == value)
                return stk;
            stk.pop();
        }
        node = node -> right;
    }
    return stk;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    Tree tree;
    creatBiTree(tree.root);
    getchar();
    // ----------------------------------------
    printf("preorder:  ");
    preorder(tree.root);
    printf("\n");

    printf("inorder:   ");
    inorder(tree.root);
    printf("\n");

    printf("postorder: ");
    postorder(tree.root);
    printf("\n\n");
    // ----------------------------------------

    // The depth of the tree
    int TreeDepth = treeDepth(tree.root);
    printf("TreeDepth       = %d\n", TreeDepth);

    // The number of the tree's nodes
    int TreeSumNode = treeSumNode(tree.root);
    printf("TreeSumNode     = %d\n", TreeSumNode);

    // The number of the tree's left nodes
    int TreeSumLeftNode = treeSumLeftNode(tree.root);
    printf("TreeSumLeftNode = %d\n", TreeSumLeftNode);

    // The depth of a left
    int LeftDepth = 1;
    bool flag = false;
    char value = '6';
    searchLayer(tree.root, value, LeftDepth, flag);
    printf("LeftDepth       = %d\n", LeftDepth);

    // ----------------------------------------
    printf("\n");
    printf("norePreorder:  ");
    norePreorder(tree);
    printf("\n");

    printf("noreInorder1:  ");
    noreInorder1(tree);
    printf("\n");

    printf("noreInorder2:  ");
    noreInorder2(tree);
    printf("\n");

    printf("norePostorder: ");
    norePostorder(tree);
    printf("\n\n");
    // ----------------------------------------

    // 根节点到叶子结点的路径
    char ch = '5';
    stack<Node> stk = getRoute(tree, ch);
    stack<char> tem;
    if (stk.empty())
        printf("can not find the number\n");
    else {
        printf("the route of '%c' is: ", ch);
        while (!stk.empty()) {
            Node *node = &stk.top();
            tem.push(node -> data);
            stk.pop();
        }
        while (!tem.empty()) {
            char ch = tem.top();
            printf("%c", ch);
            tem.pop();
            if (!tem.empty())
                printf(" -> ");
        }
        printf("\n");
    }
    printf("\n");

    creatBiTree(tree.root);
    getchar();
    printf("preorder:  ");
    preorder(tree.root);
    printf("\n");

    printf("inorder:   ");
    inorder(tree.root);
    printf("\n");

    printf("postorder: ");
    postorder(tree.root);
    printf("\n\n");
    return 0;
}
