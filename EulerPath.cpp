class Solution {
public:
    void dfs(int node, unordered_map<int,vector<int>>& adj, vector<int> &EulerPath){
        stack<int> st;
        st.push(node);

        while(!st.empty()){
            int curr = st.top();
            if(!adj[curr].empty()){
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            }
            else{
                EulerPath.push_back(curr);
                st.pop();
            }
        }
        
    }
    <vector<int> EulerPath(vector<vector<int>>& pairs) {
        // 1. Create adjacency list 
        // 2. Build indegree and outdegree of all vertices
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> indegree, outdegree;
        
        for(auto pair : pairs){
            int u = pair[0];
            int v = pair[1];
            
            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;

        }

        // 3. Find start node
        int startNode = pairs[0][0];
        for(auto &it :adj){
            int node = it.first;
            if(outdegree[node] - indegree[node] == 1){
                startNode = node;
                break;
            }
        }

        // 4. Perform dfs to store Euler's Path
        vector<int> EulerPath;
        
        dfs(startNode,adj, EulerPath);
        reverse(begin(EulerPath), end(EulerPath));

        // for(auto ele :EulerPath ){
        //     cout << ele << " ";
        // }

      return EulerPath;

        
    }
};
