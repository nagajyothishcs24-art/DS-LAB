#include <stdio.h>
#include <stdlib.h>
#define MAX 10
struct node {
    int vertex;
    struct node *next;
};
int queue[MAX];
int f = -1, r = -1;
int visited[MAX];
struct node *adj[MAX];
struct node* createNode(int v) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void enqueue(int v) {
    if (r == MAX - 1)
        return;
    if (f == -1)
        f = 0;
    queue[++r] = v;
}
int dequeue() {
    if (f == -1 || f > r)
        return -1;
    return queue[f++];
}
void bfs(int start) {
    struct node *temp;
    int v;
    enqueue(start);
    visited[start] = 1;
    while (f <= r) {
        v = dequeue();
        printf("%d ", v);
        temp = adj[v];
        while (temp != NULL) {
            if (visited[temp->vertex] == 0) {
                enqueue(temp->vertex);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}
int main() {
    int n, edges, i, src, dest, start;
    printf("Enter no.of vertices: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }
    printf("Enter no.of edges: ");
    scanf("%d", &edges);
    for (i = 0; i < edges; i++) {
        printf("Enter edge (source-destination): ");
        scanf("%d %d", &src, &dest);
        struct node *newNode = createNode(dest);
        newNode->next = adj[src];
        adj[src] = newNode;
        newNode = createNode(src);
        newNode->next = adj[dest];
        adj[dest] = newNode;
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    printf("BFS traversal: ");
    bfs(start);
    return 0;
}
