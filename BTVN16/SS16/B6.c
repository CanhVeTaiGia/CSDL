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
int Count(Node* root, int x) {
    if (root == NULL) {
        return 0;
    }
    int count = 0;
    if (root->data > x && (root->left != NULL || root->right != NULL)) {
        count = 1;
    }
    return count + Count(root->left, x) + Count(root->right, x);
}
int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);
    root->right->right->left = createNode(7);
    root->right->right->right = createNode(7);
    root->right->right->left->right = createNode(9);
    root->right->right->left->left = createNode(20);
    int x;
    printf("nhap x:");
    scanf("%d", &x);
    printf("%d\n", Count(root, x));
}
