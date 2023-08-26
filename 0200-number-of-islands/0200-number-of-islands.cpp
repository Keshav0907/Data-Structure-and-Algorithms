class Solution {
private:

    void bfs(int row,int col,vector<vector<int>> &visited,vector<vector<char>> &grid) {
        
        if(row<0 || row>grid.size() || col < 0 || col > grid[0].size() || visited[row][col]==1) {
            return;
        }
        
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col] = 1;
        while(!q.empty()) {
            
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int dx[] = {1,0,-1,0};
            int dy[] = {0,1,0,-1};
            
            for(int i=0; i<4; i++) {
                
                int nr = r + dx[i];
                int nc = c + dy[i];
                
                if(nr < grid.size() && nr>=0 && nc<grid[0].size() && nc>=0 && visited[nr][nc]!=1 && grid[nr][nc]!='0') {
                    q.push({nr,nc});
                    visited[nr][nc]=1;
                }
                
                
            }
            
        }
        
        return;
        
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();


        // visited matrix
        vector<vector<int>> vis(n,vector<int>(m,0));  // Unvisited

        int cnt = 0;

        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // Unvisited node + 1 = cnt++ by any traversal
                if(grid[i][j] =='1' && !vis[i][j]){
                    //BFS
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }

        return cnt;
    }
};