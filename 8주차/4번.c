// 4번
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

int findMax(Node* root) {
    if (root == NULL) return -99999;
    int lMax = findMax(root->left);
    int rMax = findMax(root->right);
    int m = root->data;
    if (lMax > m) m = lMax;
    if (rMax > m) m = rMax;
    return m;
}

int findMin(Node* root) {
    if (root == NULL) return 99999;
    int lMin = findMin(root->left);
    int rMin = findMin(root->right);
    int m = root->data;
    if (lMin < m) m = lMin;
    if (rMin < m) m = rMin;
    return m;
}

int main() {
    Node* root = buildTree();
    printf("최소값 : %d\n", findMin(root));
    printf("최대값 : %d\n", findMax(root));
    return 0;
}