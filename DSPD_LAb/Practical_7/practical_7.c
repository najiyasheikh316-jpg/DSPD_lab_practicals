
// Consider the undirected graph G, consisting of n nodes laid out in a 3 -by- 3 grid: Start searching at node 1, and break ties for exploring the next node based on lower numerical order (i.e. add nodes to a queue low to high, add nodes to a stack high to low). (a) In what order are nodes marked as explored by BFS? (b) In what order are nodes marked as explored by DFS?

#include <stdio.h>

int adj[20][20], visited[20];
int n;

void BFS(int start) {
    int queue[20], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 1; i <= n; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void DFS(int node) {
    printf("%d ", node);
    visited[node] = 1;
    for (int i = n; i >= 1; i--) {
        if (adj[node][i] && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;  // undirected graph
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    printf("\nBFS Traversal: ");
    for (int i = 0; i <= n; i++) visited[i] = 0;
    BFS(start);

    printf("\nDFS Traversal: ");
    for (int i = 0; i <= n; i++) visited[i] = 0;
    DFS(start);

    return 0;
}
