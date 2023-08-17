class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        
        for(int i=0; i<grid.size(); i++){
            sort(grid[i].begin(),grid[i].end());
        }
        
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for(int j=n-1; j>=0; j--) {
            
            int maxi = -1;
            
            for(int i=0; i<m; i++) {
                maxi = max(maxi,grid[i][j]);
            }
            
            res += maxi;
        }
    
        return res;
        
    }
};