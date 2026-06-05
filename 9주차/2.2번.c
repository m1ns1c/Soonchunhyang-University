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
    Node* root               = newNode(18);
    root->left               = newNode(7);
    root->right              = newNode(26);
    root->left->left         = newNode(3);
    root->left->right        = newNode(12);
    root->right->right       = newNode(31);
    root->right->right->left = newNode(27);
    return root;
}

/* BST 탐색 — 없으면 삽입 */
Node* searchOrInsert(Node* root, int target) {
    if (root == NULL) return newNode(target);
    if (target == root->data) {
        printf("이미 존재하는 값입니다.\n");
    } else if (target < root->data) {
        root->left  = searchOrInsert(root->left,  target);
    } else {
        root->right = searchOrInsert(root->right, target);
    }
    return root;
}

/* 중위순회 출력 */
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* root = buildTree();
    int target = 19;

    printf("검색할 값: %d\n", target);
    root = searchOrInsert(root, target);
    printf("삽입 완료. 중위 순회 결과:\n");
    inorder(root);
    printf("\n");
    return 0;
}