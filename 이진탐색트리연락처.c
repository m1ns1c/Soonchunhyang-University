#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int birth;
    char phone[20];
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(char* name, int birth, char* phone) {
    Node* n = (Node*)malloc(sizeof(Node));
    strcpy(n->name, name);
    n->birth = birth;
    strcpy(n->phone, phone);
    n->left = n->right = NULL;
    return n;
}

Node* insert(Node* root, char* name, int birth, char* phone) {
    if (root == NULL) return newNode(name, birth, phone);
    int cmp = strcmp(name, root->name);
    if (cmp < 0) root->left  = insert(root->left,  name, birth, phone);
    else if (cmp > 0) root->right = insert(root->right, name, birth, phone);
    else printf("이미 존재하는 친구입니다.\n");
    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

Node* deleteNode(Node* root, char* name) {
    if (root == NULL) { printf("존재하지 않는 친구입니다.\n"); return NULL; }
    int cmp = strcmp(name, root->name);
    if (cmp < 0) root->left  = deleteNode(root->left,  name);
    else if (cmp > 0) root->right = deleteNode(root->right, name);
    else {
        if (root->left == NULL) {
            Node* tmp = root->right; free(root); return tmp;
        } else if (root->right == NULL) {
            Node* tmp = root->left; free(root); return tmp;
        } else {
            Node* succ = findMin(root->right);
            strcpy(root->name, succ->name);
            root->birth = succ->birth;
            strcpy(root->phone, succ->phone);
            root->right = deleteNode(root->right, succ->name);
        }
    }
    return root;
}

Node* search(Node* root, char* name) {
    if (root == NULL) return NULL;
    int cmp = strcmp(name, root->name);
    if (cmp == 0) return root;
    else if (cmp < 0) return search(root->left,  name);
    else              return search(root->right, name);
}

Node* update(Node* root, char* name) {
    Node* target = search(root, name);
    if (target == NULL) { printf("존재하지 않는 친구입니다.\n"); return root; }
    printf("%s의 출생년도: ", name);
    scanf("%d", &target->birth);
    printf("%s의 전화번호: ", name);
    scanf("%s", target->phone);
    return root;
}

int countNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorderName(Node* root) {
    if (root == NULL) return;
    inorderName(root->left);
    printf("성명: %s\n출생년도: %d\n전화번호: %s\n", root->name, root->birth, root->phone);
    inorderName(root->right);
}

void reverseInorderName(Node* root) {
    if (root == NULL) return;
    reverseInorderName(root->right);
    printf("성명: %s\n출생년도: %d\n전화번호: %s\n", root->name, root->birth, root->phone);
    reverseInorderName(root->left);
}

void inorderBirth(Node* root, Node** arr, int* idx) {
    if (root == NULL) return;
    inorderBirth(root->left, arr, idx);
    arr[(*idx)++] = root;
    inorderBirth(root->right, arr, idx);
}

int cmpBirthAsc(const void* a, const void* b) {
    return (*(Node**)a)->birth - (*(Node**)b)->birth;
}

int cmpBirthDesc(const void* a, const void* b) {
    return (*(Node**)b)->birth - (*(Node**)a)->birth;
}

void printByBirth(Node* root, int asc) {
    int cnt = countNodes(root);
    Node** arr = (Node**)malloc(cnt * sizeof(Node*));
    int idx = 0;
    inorderBirth(root, arr, &idx);
    qsort(arr, cnt, sizeof(Node*), asc ? cmpBirthAsc : cmpBirthDesc);
    for (int i = 0; i < cnt; i++)
        printf("성명: %s\n출생년도: %d\n전화번호: %s\n", arr[i]->name, arr[i]->birth, arr[i]->phone);
    free(arr);
}

int main() {
    Node* root = NULL;
    int choice;
    char name[50], phone[20];
    int birth;

    while (1) {
        printf("1)입력, 2)출력, 3)삭제, 4)검색, 5)수정, 6)정렬 7)총인원 8)출생년도정렬 : ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("친구성명: "); scanf("%s", name);
            printf("친구출생년도: "); scanf("%d", &birth);
            printf("친구전화번호: "); scanf("%s", phone);
            root = insert(root, name, birth, phone);

        } else if (choice == 2) {
            inorderName(root);

        } else if (choice == 3) {
            printf("삭제할 친구성명: "); scanf("%s", name);
            root = deleteNode(root, name);

        } else if (choice == 4) {
            printf("친구성명?: "); scanf("%s", name);
            Node* res = search(root, name);
            if (res) printf("%s의 출생년도: %d\n%s의 전화번호: %s\n", res->name, res->birth, res->name, res->phone);
            else printf("존재하지 않는 친구입니다.\n");

        } else if (choice == 5) {
            printf("수정할 친구성명: "); scanf("%s", name);
            root = update(root, name);

        } else if (choice == 6) {
            printf("1) 성명으로 오름차순 정렬  2) 성명으로 내림차순 정렬: ");
            int sub; scanf("%d", &sub);
            if (sub == 1) inorderName(root);
            else reverseInorderName(root);

        } else if (choice == 7) {
            printf("지장된 총 친구수 : %d명\n", countNodes(root));

        } else if (choice == 8) {
            printf("1) 출생년도로 오름차순 정렬  2) 출생년도로 내림차순 정렬: ");
            int sub; scanf("%d", &sub);
            printByBirth(root, sub == 1);

        } else {
            printf("종료합니다.\n");
            break;
        }
    }
    return 0;
}