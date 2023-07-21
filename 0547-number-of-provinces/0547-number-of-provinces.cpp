class Solution {
public:
    
    void dfs(int i,vector<bool> &visited,vector<int> adj[]) {
        
        visited[i] = true;
        for(auto nbr : adj[i] ) {
            if(!visited[nbr]) {
            dfs(nbr,visited,adj);
            }
        }
        
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int V = isConnected.size();
        vector<int> adj[V];
        
        for(int i=0; i<V; i++) {
            
            for(int j=0; j<V; j++) {
                
                if(isConnected[i][j]==1 && i!=j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
                
            }
        }
        vector<bool> visited(V,false);
        
        int count = 0;
        
        for(int i=0; i<V; i++) {
            
            if(!visited[i]) {
                count++;
                dfs(i,visited,adj);
            }
            
        }
        
        return count;
        
    }
};