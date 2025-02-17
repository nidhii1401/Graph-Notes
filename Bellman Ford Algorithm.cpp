    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        int maxi = 100000000;
        vector<int> distance(V, maxi);
        distance[src] = 0;
        
        for(int i=0; i<V-1; i++){
            for(auto edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(distance[u] != maxi && distance[u]+w < distance[v]){
                    distance[v] = distance[u]+w;
                }
            }
        }
        // This loop will check for a negative cycle. If any value in the distance array changes, it indicates that there is a negative cycle present in the graph.
        for(auto edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(distance[u] != maxi && distance[u]+w < distance[v]){
                    return {-1};
                }
        }
        
        return distance;

    }
