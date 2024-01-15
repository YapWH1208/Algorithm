#include <stdbool.h>
#include <stdio.h>
#include "Graph.h"

void DFSUtil(Graph* g, int V, bool visited[]){
	visited[V] = true;
	printf("%d ", V);

	for(int adjs=0; adjs<g->V; adjs++){
		if(g->adj[V][adjs] && !visited[adjs]){
			DFSUtil(g, adjs, visited);
		}
	}
}


void DFS(Graph* g, int s){
	bool visited[MAX_VERTICES];
	for(int i=0; i<g->V; i++){
		visited[i] = false;
	}

	DFSUtil(g, s, visited);
}