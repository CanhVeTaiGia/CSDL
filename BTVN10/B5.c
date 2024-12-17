#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

Node* search(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n=== MENU ===\n");
        printf("1. Them phan tu vao cay\n");
        printf("2. Duyet cay PreOrder\n");
        printf("3. Duyet cay InOrder\n");
        printf("4. Duyet cay PostOrder\n");
        printf("5. Tim kiem phan tu trong cay\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Duyet cay PreOrder: ");
                preOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Duyet cay InOrder: ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Duyet cay PostOrder: ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                Node* found = search(root, value);
                if (found != NULL) {
                    printf("Tim thay gia tri %d trong cay\n", value);
                } else {
                    printf("Khong tim thay gia tri %d trong cay\n", value);
                }
                break;
            case 6:
                freeTree(root);
                printf("Da giai phong bo nho va thoat chuong trinh\n");
                return 0;
            default:
                printf("Lua chon khong hop le, vui long nhap lai\n");
        }
    }
}
