#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* findValue(Node* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == value) {
        return root;
    }
    if (value < root->data) {
        return findValue(root->left, value);
    }
    return findValue(root->right, value);
}

int main() {
    Node* root = createNode(8);
    root->left = createNode(3);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->left->right = createNode(6);
    root->left->right->left = createNode(4);
    root->left->right->right = createNode(7);
    root->right->right = createNode(14);
    root->right->right->left = createNode(13);

    int searchValue = 20;
    Node* result = findValue(root, searchValue);
    if (result != NULL) {
        printf("Tim thay gia tri %d trong cay.\n", result->data);
    } else {
        printf("Khong tim thay gia tri %d trong cay.\n", searchValue);
    }
}
