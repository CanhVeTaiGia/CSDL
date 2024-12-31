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

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->root);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->root);
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->root);
}

void convertTreeToGraph(Node *root, int adjList[MAX][MAX], int size) {
    if (root == NULL)
        return;

    if (root->left) {
        adjList[root->root][root->left->root] = 1;
        adjList[root->left->root][root->root] = 1;
        convertTreeToGraph(root->left, adjList, size);
    }
    if (root->right) {
        adjList[root->root][root->right->root] = 1;
        adjList[root->right->root][root->root] = 1;
        convertTreeToGraph(root->right, adjList, size);
    }
}

void DFS(int start, int visited[], int adjList[MAX][MAX], int size) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < size; i++) {
        if (adjList[start][i] == 1 && !visited[i]) {
            DFS(i, visited, adjList, size);
        }
    }
}

void BFS(int start, int visited[], int adjList[MAX][MAX], int size) {
    int queue[MAX], front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < size; i++) {
            if (adjList[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    int n, val;
    do
    {
        printf("Nhap so luong gia tri vao cay (0 < n <= 10): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 10);

    for (int i = 0; i < n; i++)
    {
        printf("nut thu %d: ", i + 1);
        scanf("%d", &val);
        insert(&root, val);
    }

    printf("preOrder: ");
    preOrder(root);
    printf("\n");

    printf("inOrder: ");
    inOrder(root);
    printf("\n");

    printf("postOrder: ");
    postOrder(root);    
    printf("\n");

    int adjList[MAX][MAX] = {0};
    convertTreeToGraph(root, adjList, MAX);

    printf("DFS: ");
    int visited[MAX] = {0};
    DFS(root->root, visited, adjList, MAX);
    printf("\n");

    printf("BFS: ");
    for (int i = 0; i < MAX; i++)
        visited[i] = 0;
    BFS(root->root, visited, adjList, MAX);
    printf("\n");
    return 0;
}