#include <iostream>
#include <vector>

#define MAX_VERTICES 50

using namespace std;

typedef struct graph{
    int V;//number of vertices
    bool adj[MAX_VERTICES][MAX_VERTICES];//adjacency list
} Graph;

int binarySearch(vector<int> &arr, int target);
void BFS(Graph* g, int s);
void DFS(Graph* g, int s);
void dijkstra(Graph* g, int src);
