class Solution {
public:
    
    
    void dfs(int i,int j,vector<vector<int>> &grid,int &count) {
        
        if(i<0 || i>=grid.size() || j < 0 || j >=grid[0].size() || grid[i][j]==0) {
            count++;
            return;
        }
        
        if(grid[i][j]==-1) return;
        grid[i][j] = -1;
        
        dfs(i+1,j,grid,count);
        dfs(i-1,j,grid,count);
        dfs(i,j+1,grid,count);
        dfs(i,j-1,grid,count);
        return;
    }
    
    
    int islandPerimeter(vector<vector<int>>& grid) {
     
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<m; i++) {
            
            for(int j=0; j<n; j++) {
            
                if(grid[i][j]==1) {
                    dfs(i,j,grid,count);
                    break;
                }

            }
        }
        
        return count;
        
    }
};