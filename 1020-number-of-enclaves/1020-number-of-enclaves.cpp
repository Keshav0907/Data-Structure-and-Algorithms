class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        queue<pair<int,int>> q;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                
                if(i==0 || j==0 || i==m-1 || j==n-1) {
                    
                    if(grid[i][j]==1) {
                        q.push({i,j});
                        visited[i][j]=1;
                    }
                
                }
            }
        }
        
        
        int dx[] ={-1,0,1,0};
        int dy[] = {0,-1,0,1};
        while(!q.empty()) {
        
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++) {
                
                int nr = row + dx[i];
                int nc = col + dy[i];
                
                if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc] && grid[nr][nc]==1) {
                    q.push({nr,nc});
                    visited[nr][nc]=1;
                }
                
                   
            }
        
        }
        
        int count = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1 && !visited[i][j]) {
                    count++;
                }
            }
        }
        
        
        return count;
        
    }
};