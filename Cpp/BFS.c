#include <stdbool.h>
#include <stdio.h>
#include "Graph.h"

void BFS(Graph* g, int s){

	// Visited list
	bool visited[MAX_VERTICES];
	for(int i=0; i<g->V; i++){
		visited[i] = false;
	}

	// Queue for BFS
	int queue[MAX_VERTICES];
	int front = 0, rear = 0;

	// Mark current node as visited
	visited[s] = true;
	queue[rear++] = s;

	while(front != rear){
		s = queue[front++];
		printf("%d ", s);

		for(int adjs=0; adjs<g->V; adjs++){
			if(g->adj[s][adjs] && !visited[adjs]){
				visited[adjs] = true;
				queue[rear++] = adjs;
			}
		}
	}
}