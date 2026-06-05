// 2번
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

/* 후위순회: 자식 먼저 처리 후 현재 노드 출력 */
int sumSubTree(Node* root) {
    if (root == NULL) return 0;
    int total = root->data + sumSubTree(root->left) + sumSubTree(root->right);
    printf("%d번 노드과 서브 트리노드 총합: %d\n", root->data, total);
    return total;
}

int main() {
    Node* root = buildTree();
    sumSubTree(root);
    return 0;
}