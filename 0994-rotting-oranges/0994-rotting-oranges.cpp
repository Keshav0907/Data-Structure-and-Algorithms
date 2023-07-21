class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==2) {
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        
        int tm = 0;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        while(!q.empty()) {
            
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            tm = max(time,tm);
            q.pop();
            
            for(int i=0; i<4; i++) {
                
                int nRow = row + dx[i];
                int nCol = col + dy[i];
                
                if(nRow >=0 && nRow<m && nCol>=0 && nCol<n &&!visited[nRow][nCol] && grid[nRow][nCol]==1) {
                    visited[nRow][nCol]=1;
                    q.push({{nRow,nCol},time+1});
                    
                }
                
            }
            
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) {
                if(!visited[i][j] && grid[i][j]==1){
                    return -1;
                }
            }
        }
        
    
        return tm;
        
    }
};