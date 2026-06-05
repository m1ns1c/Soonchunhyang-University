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
    Node* root               = newNode(18);
    root->left               = newNode(7);
    root->right              = newNode(26);
    root->left->left         = newNode(3);
    root->left->right        = newNode(12);
    root->right->right       = newNode(31);
    root->right->right->left = newNode(27);
    return root;
}

Node* deleteNode(Node* root, int target) {
    if (root == NULL) return NULL;

    if (target < root->data) {
        root->left  = deleteNode(root->left,  target);
    } else if (target > root->data) {
        root->right = deleteNode(root->right, target);
    } else {
        if (root->left == NULL) {
            Node* tmp = root->right;
            free(root);
            return tmp;
        } else if (root->right == NULL) {
            Node* tmp = root->left;
            free(root);
            return tmp;
        } else {
            Node* succ = root->right;
            while (succ->left != NULL) succ = succ->left;
            root->data  = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* root = buildTree();
    root = deleteNode(root, 31);
    printf("중위 순회 결과:\n");
    inorder(root);
    printf("\n");
    return 0;
}