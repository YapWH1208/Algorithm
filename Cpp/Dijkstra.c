#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include "Graph.h"

void dijkstra(Graph* g, int src) {
    int dist[MAX_VERTICES];
    bool sptSet[MAX_VERTICES];

    for (int i = 0; i < g->V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < g->V - 1; count++) {
        int u = -1;
        int minDist = INT_MAX;

        for (int v = 0; v < g->V; v++) {
            if (!sptSet[v] && dist[v] < minDist) {
                u = v;
                minDist = dist[v];
            }
        }

        if (u == -1) {
            break; // No reachable vertices left
        }

        sptSet[u] = true;

        for (int v = 0; v < g->V; v++) {
            if (!sptSet[v] && g->adj[u][v] && dist[u] != INT_MAX &&
                dist[u] + g->weight[u][v] < dist[v]) {
                dist[v] = dist[u] + g->weight[u][v];
            }
        }
    }

    printf("Shortest distances from source vertex %d:\n", src);
    for (int i = 0; i < g->V; i++) {
        printf("To vertex %d: %d\n", i, dist[i]);
    }
}
