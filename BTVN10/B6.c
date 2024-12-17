#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Graph {
    int vertices;
    int matrix[MAX][MAX];
} Graph;

typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph->matrix[i][j] = 0;
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int isDirected) {
    graph->matrix[src][dest] = 1;
    if (!isDirected) {
        graph->matrix[dest][src] = 1;
    }
}

void displayGraph(Graph* graph) {
    printf("Ma tran ke cua do thi:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

void DFSUtil(Graph* graph, int vertex, int visited[]) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < graph->vertices; i++) {
        if (graph->matrix[vertex][i] && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

void DFS(Graph* graph, int startVertex) {
    int visited[MAX] = {0};
    printf("Duyet DFS: ");
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

void BFS(Graph* graph, int startVertex) {
    int visited[MAX] = {0};
    Queue* q = createQueue();

    printf("Duyet BFS: ");
    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->matrix[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices, choice, src, dest, startVertex, isDirected;
    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Do thi co huong? (1-Co huong, 0-Khong huong): ");
    scanf("%d", &isDirected);

    while (1) {
        printf("\n=== MENU ===\n");
        printf("1. Them canh\n");
        printf("2. Hien thi ma tran ke\n");
        printf("3. Duyet DFS\n");
        printf("4. Duyet BFS\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap dinh nguon va dinh dich: ");
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest, isDirected);
                break;
            case 2:
                displayGraph(graph);
                break;
            case 3:
                printf("Nhap dinh bat dau DFS: ");
                scanf("%d", &startVertex);
                DFS(graph, startVertex);
                break;
            case 4:
                printf("Nhap dinh bat dau BFS: ");
                scanf("%d", &startVertex);
                BFS(graph, startVertex);
                break;
            case 5:
                free(graph);
                printf("Thoat chuong trinh\n");
                return 0;
            default:
                printf("Lua chon khong hop le\n");
        }
    }
    return 0;
}
