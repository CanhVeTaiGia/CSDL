#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node
{
    int root;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->root = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node **root, int val)
{
    if (*root == NULL)
    {
        *root = createNode(val);
        return;
    }

    if (val < (*root)->root)
    {
        insert(&(*root)->left, val);
    }
    else if (val > (*root)->root)
    {
        insert(&(*root)->right, val);
    }
}

void preOrder(Node **root)
{
    if (*root == NULL)
        return;
    printf("%d ", (*root)->root);
    preOrder(&(*root)->left);
    preOrder(&(*root)->right);
}

void inOrder(Node **root)
{
    if (*root == NULL)
        return;
    inOrder(&(*root)->left);
    printf("%d ", (*root)->root);
    inOrder(&(*root)->right);
}

void postOrder(Node **root)
{
    if (*root == NULL)
        return;
    postOrder(&(*root)->left);
    postOrder(&(*root)->right);
    printf("%d ", (*root)->root);
}

int main()
{
    Node *root = NULL;
    int n, val;
    do
    {
        printf("Nhap so luong gia tri vao cay (0 < n <= MAX): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 10);

    for (int i = 0; i < n; i++)
    {
        printf("nut thu %d: ", i + 1);
        scanf("%d", &val);
        insert(&root, val);
    }

    printf("preOrder: ");
    preOrder(&root);
    printf("\n");

    printf("inOrder: ");
    inOrder(&root);
    printf("\n");

    printf("postOrder: ");
    postOrder(&root);
    printf("\n");
    return 0;
}