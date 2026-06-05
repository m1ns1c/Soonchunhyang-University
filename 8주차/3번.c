// 3번
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

void printGreater(Node* root, int value) {
    if (root == NULL) return;
    printGreater(root->left, value);
    if (root->data > value)
        printf("%d보다 큰 노드 : %d\n", value, root->data);
    printGreater(root->right, value);
}

int main() {
    Node* root = buildTree();
    int value;
    printf("값을 입력하시오: ");
    scanf("%d", &value);
    printGreater(root, value);
    return 0;
}