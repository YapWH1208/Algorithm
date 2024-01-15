#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct graph{
    int V;//number of vertices
    bool adj[MAX_VERTICES][MAX_VERTICES];//adjacency list
    int weight[MAX_VERTICES][MAX_VERTICES];//weight of edges
} Graph;

Graph* createGraph(int V) {
    Graph* g = malloc(sizeof(Graph));
    g->V = V;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = false;
            g->weight[i][j] = INT_MAX; // Initialize weights to infinity
        }
    }

    return g;
}


void addEdge(Graph* g, int v, int w, int weight) {
    g->adj[v][w] = true;
    g->weight[v][w] = weight;
}