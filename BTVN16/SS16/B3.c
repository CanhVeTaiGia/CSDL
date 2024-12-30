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


int countLeaves(Node* root) {
    if (root == NULL) {
        return 0;
    } 
    if (root->left == NULL && root->right == NULL) {
        return 0;
    } else {
        return countLeaves(root->left) + countLeaves(root->right);
    }
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
    root->right->right->left->left = createNode(7);
    printf("%d",countLeaves(root));
}
