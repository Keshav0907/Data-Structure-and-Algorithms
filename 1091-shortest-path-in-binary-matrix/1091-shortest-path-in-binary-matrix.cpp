class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) {
            return -1;
        }
        if(0 == n-1) return 1;
        
        queue<pair<int,pair<int,int>>> q;
        
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        
        dist[0][0] = 0;
        
        q.push({1,{0,0}});
        
        while(!q.empty()) {
            
            int distance = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();            
            for(int i=-1; i<=1; i++) {
                for(int j=-1; j<=1; j++) {
                    
                    int dr = row + i;
                    int dc= col + j;
                    
                    if(dr>=0 && dc>=0 && dr<n && dc<n && grid[dr][dc]!=1) {
                        
                      if(dist[dr][dc] > distance+1) {
                          
                          dist[dr][dc] = distance+1;
                          q.push({distance+1,{dr,dc}});
                          
                      }  
                        
                        
                    }
                    
                }
            }
            
            
        }
        
        return dist[n-1][n-1]==1e9 ? -1 : dist[n-1][n-1];
        
    }
};