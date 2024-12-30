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
int Max(Node* root) {
    if (root == NULL) {
        return INT_MIN;
    } 
    int max = root->data;
    int leftMax = Max(root->left);
    int rightMax = Max(root->right);
    max = (leftMax > max) ? leftMax : max;
    max = (rightMax > max) ? rightMax : max;
    return max;
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
    printf("%d",Max(root));
}
