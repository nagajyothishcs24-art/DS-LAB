#include <stdio.h>
#include <stdlib.h>
struct node {
    int vertex;
    struct node *next;
};
struct node *adj[10];
int visited[10];
int n;
struct node *createNode(int v) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void addEdge(int src, int dest) {
    struct node *newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;
}
void DFS(int v) {
    struct node *temp;
    visited[v] = 1;
    printf("%d ", v);
    temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }
}
int main() {
    int i, e, s, d, start;
    printf("Enter no.of vertices: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }
    printf("Enter no.of edges: ");
    scanf("%d", &e);
    printf("Enter edges (source-destination):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d", &s, &d);
        addEdge(s, d);
        addEdge(d, s);
    }
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);
    printf("DFS Traversal: ");
    DFS(start);
    return 0;
}
