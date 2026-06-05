// 1번
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
    Node* root    = newNode(3);
    root->left    = newNode(2);
    root->right   = newNode(5);
    root->left->left   = newNode(1);
    root->right->left  = newNode(4);
    root->right->right = newNode(9);
    return root;
}

int sumAll(Node* root) {
    if (root == NULL) return 0;
    return root->data + sumAll(root->left) + sumAll(root->right);
}

int main() {
    Node* root = buildTree();
    printf("모든 노드 값의 총합: %d\n", sumAll(root));
    return 0;
}