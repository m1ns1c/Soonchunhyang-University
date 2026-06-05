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
    Node* root     = newNode(18);
    root->left     = newNode(7);
    root->right    = newNode(26);
    root->left->left  = newNode(3);
    root->left->right = newNode(12);
    root->right->right       = newNode(31);
    root->right->right->left = newNode(27);
    return root;
}

void search(Node* root, int target) {
    int cnt = 0;
    Node* cur = root;
    while (cur != NULL) {
        cnt++;
        if (target == cur->data) {
            printf("%d번만에 찾았습니다.\n", cnt);
            return;
        } else if (target < cur->data) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    printf("찾지 못했습니다.\n");
}

int main() {
    Node* root = buildTree();
    int target;
    printf("검색할 값은? ");
    scanf("%d", &target);
    search(root, target);
    return 0;
}