#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Graph {
    int V;
    int adj[MAX][MAX];
} Graph;

void initGraph(Graph *g, int v) {
    g->V = v;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int src, int dest) {
    g->adj[src][dest] = 1;
    g->adj[dest][src] = 1;
}

void DFS(Graph *g, int start, int visited[]) {
    visited[start] = 1;
    printf("%d ", start);
    for (int i = 0; i < g->V; i++) {
        if (g->adj[start][i] == 1 && !visited[i]) {
            DFS(g, i, visited);
        }
    }
}

int main() {
    Graph g;
    int v, e, src, dest, start;

    printf("Nhap so dinh: ");
    scanf("%d", &v);

    if (v > MAX) {
        printf("So dinh vuot qua gioi han cho phep (%d).\n", MAX);
        return 1;
    }

    initGraph(&g, v);

    printf("Nhap so canh: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        printf("Nhap canh %d (nguon dich): ", i + 1);
        scanf("%d %d", &src, &dest);
        if (src >= v || dest >= v || src < 0 || dest < 0) {
            printf("Canh khong hop le! Vui long nhap dinh tu 0 den %d.\n", v - 1);
            i--;
        } else {
            addEdge(&g, src, dest);
        }
    }

    int visited[MAX] = {0};
    printf("Nhap dinh bat dau cho DFS: ");
    scanf("%d", &start);

    if (start >= v || start < 0) {
        printf("Dinh bat dau khong hop le.\n");
        return 1;
    }

    printf("Duyet DFS bat dau tu dinh %d: ", start);
    DFS(&g, start, visited);
    printf("\n");

    return 0;
}
