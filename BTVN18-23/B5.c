#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int vertex;
    struct node* next;
} Node;

typedef struct graph {
    int vertices;
    int adjMatrix[MAX][MAX];
    Node* adjList[MAX];
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdgeMatrix(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void addEdgeList(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void removeEdgeMatrix(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 0;
    graph->adjMatrix[dest][src] = 0;
}

void removeEdgeList(Graph* graph, int src, int dest) {
    Node *temp = graph->adjList[src], *prev = NULL;
    while (temp != NULL && temp->vertex != dest) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (prev == NULL) graph->adjList[src] = temp->next;
    else prev->next = temp->next;


    temp = graph->adjList[dest];
    prev = NULL;
    while (temp != NULL && temp->vertex != src) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (prev == NULL) graph->adjList[dest] = temp->next;
    else prev->next = temp->next;
}

void DFSUtil(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    Node* temp = graph->adjList[vertex];
    while (temp != NULL) {
        if (!visited[temp->vertex]) DFSUtil(graph, temp->vertex, visited);
        temp = temp->next;
    }
}

void DFS(Graph* graph, int start) {
    int visited[MAX] = {0};
    DFSUtil(graph, start, visited);
}

void BFS(Graph* graph, int start) {
    int visited[MAX] = {0};
    int queue[MAX], front = -1, rear = -1;
    queue[++rear] = start;
    visited[start] = 1;

    while (front != rear) {
        int vertex = queue[++front];
        printf("%d ", vertex);
        Node* temp = graph->adjList[vertex];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                queue[++rear] = temp->vertex;
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    Graph* graph = createGraph(5);

    addEdgeMatrix(graph, 0, 1);
    addEdgeMatrix(graph, 0, 4);
    addEdgeMatrix(graph, 1, 2);
    addEdgeMatrix(graph, 1, 3);
    addEdgeMatrix(graph, 1, 4);
    addEdgeMatrix(graph, 2, 3);
    addEdgeMatrix(graph, 3, 4);

    printf("DFS tu dinh 0: ");
    DFS(graph, 0);
    printf("\n");

    printf("BFS tu dinh 0: ");
    BFS(graph, 0);
    printf("\n");

    removeEdgeMatrix(graph, 1, 4);

    printf("DFS sau khi xoa canh (1, 4): ");
    DFS(graph, 0);
    printf("\n");

    return 0;
}
