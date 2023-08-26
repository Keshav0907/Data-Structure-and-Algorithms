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
    
    void dfs(int row,int col,vector<vector<int>> &visited,vector<vector<char>> &grid) {
        
        if(row >= grid.size() || row<0 || col>=grid[0].size() || col<0) {
            return;
        }
        
        if(visited[row][col] || grid[row][col]=='0') {
            return;
        }
        
        visited[row][col]=1;
        
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        
        for(int i=0; i<4; i++) {
            
            int nr = row + dx[i];
            int nc = col + dy[i];
            
            if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]=='1' && !visited[nr][nc]) {
                dfs(nr,nc,visited,grid);
            }
            
        }
        
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();


        // visited matrix
        vector<vector<int>> vis(n,vector<int>(m,0));  // Unvisited

        int cnt = 0;

        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         // Unvisited node + 1 = cnt++ by any traversal
        //         if(grid[i][j] =='1' && !vis[i][j]){
        //             //BFS
        //             cnt++;
        //             bfs(i,j,vis,grid);
        //         }
        //     }
        // }
        
           for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // Unvisited node + 1 = cnt++ by any traversal
                if(grid[i][j] =='1' && !vis[i][j]){
                    //BFS
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }

        return cnt;
    }
};