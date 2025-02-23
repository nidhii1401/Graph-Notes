class Solution {
  public:
    void dfsFill(int u, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st){
        visited[u] = true;
        
        for(int &v : adj[u]){
            if(!visited[v]) dfsFill(v, adj, visited, st);
        }
        st.push(u);
    }
    
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited){
        visited[node] = true;
        for(int &v : adj[node]){
            if(!visited[v]) dfs(v, adj, visited);
        }
    }
    
    int kosaraju(vector<vector<int>> &adj) {
        // 1. Store original graph in Topological order
        stack<int> st;
        int V = adj.size();
        vector<bool> visited(V,false);
        
        for(int i=0; i<V; i++){
            if(!visited[i]) dfsFill(i, adj, visited, st);
        }
        
        //2.  Reverse all the edges of graph
        
        vector<vector<int>> reverseAdj(V);
        for(int u=0; u<V; u++){
            for(auto &v: adj[u]){
                reverseAdj[v].push_back(u);
            }
        }
        
        // 3. Call dfs in topological order
        
        int cnt = 0;
        visited = vector<bool>(V,false);
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                dfs(node, reverseAdj, visited);
                cnt++;
            }
        }
        return cnt;
        
    }
};
