// 6번
#include <stdio.h>
#include <stdlib.h>

typedef struct TNode {
    int data;
    struct TNode* left;
    struct TNode* right;
    int isThread;   
} TNode;

TNode* newTNode(int data) {
    TNode* n = (TNode*)malloc(sizeof(TNode));
    n->data = data;
    n->left = n->right = NULL;
    n->isThread = 0;
    return n;
}

TNode* buildTree() {
    TNode* n18 = newTNode(18);
    TNode* n7  = newTNode(7);
    TNode* n26 = newTNode(26);
    TNode* n3  = newTNode(3);
    TNode* n12 = newTNode(12);
    TNode* n31 = newTNode(31);
    TNode* n27 = newTNode(27);

    n18->left  = n7;
    n18->right = n26;
    n7->left   = n3;
    n7->right  = n12;
    n26->right = n31;
    n31->left  = n27;

    n3->right  = n7;   n3->isThread  = 1;
    n12->right = n18;  n12->isThread = 1;
    n27->right = n31;  n27->isThread = 1;

    return n18;
}

TNode* goLeft(TNode* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

void inorder(TNode* root) {
    TNode* cur = goLeft(root);
    while (cur != NULL) {
        printf("%d ", cur->data);
        if (cur->isThread) {
            cur = cur->right;         
        } else {
            if (cur->right != NULL)
                cur = goLeft(cur->right); 
            else
                cur = NULL;
        }
    }
    printf("\n");
}

int main() {
    TNode* root = buildTree();
    printf("노드 방문 순서: ");
    inorder(root);
    return 0;
}