class Solution {
private:
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid){
        queue<pair<int,int>> q;

        int n = grid.size();
        int m = grid[0].size();

        q.push({row,col});
        vis[row][col] =1;

        int delrow[] = {0,-1,0,1};
        int delcol[] = {1,0,-1,0};

        while(!q.empty()){           
            
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] 
                    && grid[nrow][ncol] =='1'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] =1;
                }
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