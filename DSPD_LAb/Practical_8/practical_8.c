//Write a program which accepts undirected graph and a starting node, determine the lengths of the shortest paths from the starting node to all other nodes in the graph. If a node is unreachable, its distance is -1. Nodes will be numbered consecutively from 1 to n, and edges will have varying distances or lengths. Find the sub tree using kruskal's algorithm


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 50

struct Edge {
    int u, v, w;
};

int parent[MAX];
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void BFS_MST(int n, int mst[MAX][MAX], int start) {
    int visited[MAX] = {0}, dist[MAX];
    for (int i = 1; i <= n; i++) dist[i] = -1;

    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    dist[start] = 0;

    while (front < rear) {
        int node = queue[front++];
        for (int i = 1; i <= n; i++) {
            if (mst[node][i] && !visited[i]) {
                visited[i] = 1;
                dist[i] = dist[node] + mst[node][i];
                queue[rear++] = i;
            }
        }
    }

    printf("\nShortest distances from node %d in MST:\n", start);
    for (int i = 1; i <= n; i++)
        printf("Node %d : %d\n", i, dist[i]);
}

int main() {
    struct Edge edges[MAX];
    int n, e, u, v, w, start;
    int mst[MAX][MAX] = {0};
    int edgeCount = 0, totalCost = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    // Initialize parent
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    // Sort edges by weight
    for (int i = 0; i < e - 1; i++)
        for (int j = 0; j < e - i - 1; j++)
            if (edges[j].w > edges[j + 1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }

    printf("\nEdges in the MST:\n");
    for (int i = 0; i < e; i++) {
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        if (find(u) != find(v)) {
            union1(u, v);
            mst[u][v] = mst[v][u] = w;
            printf("%d -- %d  cost = %d\n", u, v, w);
            totalCost += w;
            edgeCount++;
            if (edgeCount == n - 1)
                break;
        }
    }
    printf("Total cost of MST = %d\n", totalCost);

    // Find shortest paths in MST
    BFS_MST(n, mst, start);

    return 0;
}

