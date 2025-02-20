class Solution{
public:
    typedef pair<int,int> P;
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<bool> inMST(V,false);
        int sum = 0;
        
        pq.push({0,0});
        
        while(!pq.empty()){
            
            auto p = pq.top();
            pq.pop();
            
            int wt = p.first;
            int node = p.second;
            
            if(inMST[node]) continue;
            inMST[node] = true;
            sum += wt;
            
            for(auto &temp:adj[node]){
                int neighbour = temp[0];
                int neighbour_wt = temp[1];
                
                if(!inMST[neighbour]) pq.push({neighbour_wt,neighbour});
            }
        }
        
        return sum;
        
    }
};
