#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *createBinaryTree(int n, int *values) {
    if (n <= 0) return NULL;
    Node **nodes = (Node **)malloc(n * sizeof(Node *));
    for (int i = 0; i < n; i++)
        nodes[i] = createNode(values[i]);

    for (int i = 0; i < n; i++) {
        if (2 * i + 1 < n)
            nodes[i]->left = nodes[2 * i + 1];
        if (2 * i + 2 < n)
            nodes[i]->right = nodes[2 * i + 2];
    }

    Node *root = nodes[0];
    free(nodes);
    return root;
}

void preOrder(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(Node *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

typedef struct Graph {
    int n;
    int **adjMatrix;
} Graph;

Graph *createGraph(int n, int edges[][2], int edgeCount) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->n = n;
    graph->adjMatrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph->adjMatrix[i] = (int *)calloc(n, sizeof(int));
    }

    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph->adjMatrix[u][v] = 1;
        graph->adjMatrix[v][u] = 1;
    }

    return graph;
}

void DFSUtil(Graph *graph, int v, bool *visited) {
    visited[v] = true;
    printf("%d ", v);
    for (int i = 0; i < graph->n; i++) {
        if (graph->adjMatrix[v][i] && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

void DFS(Graph *graph, int start) {
    bool *visited = (bool *)calloc(graph->n, sizeof(bool));
    DFSUtil(graph, start, visited);
    free(visited);
}

void BFS(Graph *graph, int start) {
    bool *visited = (bool *)calloc(graph->n, sizeof(bool));
    int *queue = (int *)malloc(graph->n * sizeof(int));
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < graph->n; i++) {
            if (graph->adjMatrix[v][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }

    free(queue);
    free(visited);
}

void measureTraversalTime(void (*traversalFunc)(void *), void *data, const char *label) {
    clock_t start = clock();
    traversalFunc(data);
    clock_t end = clock();
    printf("\n%s took %.5f seconds\n", label, (double)(end - start) / CLOCKS_PER_SEC);
}

void preOrderWrapper(void *data) {
    preOrder((Node *)data);
}

void inOrderWrapper(void *data) {
    inOrder((Node *)data);
}

void postOrderWrapper(void *data) {
    postOrder((Node *)data);
}

void DFSWrapper(void *data) {
    DFS((Graph *)data, 0);
}

void BFSWrapper(void *data) {
    BFS((Graph *)data, 0);
}

int main() {
    int n = 10;
    int values[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int edges[][2] = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 7}, {4, 8}, {5, 9}};
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    printf("--- Binary Tree ---\n");
    Node *root = createBinaryTree(n, values);
    measureTraversalTime(preOrderWrapper, root, "Pre-order Traversal");
    measureTraversalTime(inOrderWrapper, root, "In-order Traversal");
    measureTraversalTime(postOrderWrapper, root, "Post-order Traversal");

    printf("\n--- Graph ---\n");
    Graph *graph = createGraph(n, edges, edgeCount);
    measureTraversalTime(DFSWrapper, graph, "DFS Traversal");
    measureTraversalTime(BFSWrapper, graph, "BFS Traversal");

    return 0;
}
