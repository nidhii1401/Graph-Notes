void shortestDistance(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int node = 0; node < n; node++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][node]+mat[node][j]);
                }
            }
        }
 
}
