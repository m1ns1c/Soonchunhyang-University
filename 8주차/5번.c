// 5번
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

Node* buildTree() {
    Node* root         = newNode(3);
    root->left         = newNode(2);
    root->right        = newNode(5);
    root->left->left   = newNode(1);
    root->right->left  = newNode(4);
    root->right->right = newNode(9);
    return root;
}

int countFullNodes(Node* root) {
    if (root == NULL) return 0;
    int cnt = 0;
    if (root->left != NULL && root->right != NULL)
        cnt = 1;
    return cnt + countFullNodes(root->left) + countFullNodes(root->right);
}

void printFullNodes(Node* root) {
    if (root == NULL) return;
    if (root->left != NULL && root->right != NULL)
        printf("노드 %d\n", root->data);
    printFullNodes(root->left);
    printFullNodes(root->right);
}

int main() {
    Node* root = buildTree();
    int cnt = countFullNodes(root);
    printf("%d개 : ", cnt);
    printFullNodes(root);
    return 0;
}