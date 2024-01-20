public class Search{
    public static void BFS(int[][] graph, int start){
        boolean[] visited = new boolean[graph.length];
        Queue<Integer> q = new LinkedList<Integer>();

        visited[start] = true;
        q.add(start);

        while(!q.isEmpty()){
            int v = q.poll();
            System.out.print(v + " ");

            for(int i = 0; i < graph.length; i++){
                if(graph[v][i] == 1 && !visited[i]){
                    visited[i] = true;
                    q.add(i);
                }
            }
        }
    }

    public static void DFS(int[][] graph, int start){
        boolean[] visited = new boolean[graph.length];
        Stack<Integer> s = new Stack<Integer>();

        visited[start] = true;
        s.push(start);

        while(!s.isEmpty()){
            int v = s.pop();
            System.out.print(v + " ");

            for(int i = 0; i < graph.length; i++){
                if(graph[v][i] == 1 && !visited[i]){
                    visited[i] = true;
                    s.push(i);
                }
            }
        }
    }

    public static void binarySearch(int[] arr, int l, int r, int x){
        if(r >= l){
            int mid = l + (r-l)/2;

            if(arr[mid] == x){
                System.out.println("Found at index " + mid);
            }
            else if(arr[mid] > x){
                binarySearch(arr, l, mid-1, x);
            }
            else{
                binarySearch(arr, mid+1, r, x);
            }
        }
        else{
            System.out.println("Not found");
        }
    }

    public static void Dijkstra(int[][] graph, int start){
        int[] dist = new int[graph.length];
        boolean[] visited = new boolean[graph.length];

        for(int i = 0; i < graph.length; i++){
            dist[i] = Integer.MAX_VALUE;
        }

        dist[start] = 0;

        for(int i = 0; i < graph.length-1; i++){
            int u = minDistance(dist, visited);

            visited[u] = true;

            for(int j = 0; j < graph.length; j++){
                if(!visited[j] && graph[u][j] != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + graph[u][j] < dist[j]){
                    dist[j] = dist[u] + graph[u][j];
                }
            }
        }

        printSolution(dist);
    }

    public static int minDistance(int[] dist, boolean[] visited){
        int min = Integer.MAX_VALUE;
        int minIndex = -1;

        for(int i = 0; i < dist.length; i++){
            if(!visited[i] && dist[i] <= min){
                min = dist[i];
                minIndex = i;
            }
        }

        return minIndex;
    }

    public static void printSolution(int[] dist){
        System.out.println("Vertex \t\t Distance from Source");
        for(int i = 0; i < dist.length; i++){
            System.out.println(i + " \t\t " + dist[i]);
        }
    }
}