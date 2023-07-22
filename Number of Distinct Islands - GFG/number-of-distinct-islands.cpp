//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    private :
    
    void dfs(int row,int col,vector<vector<int>> &visited,vector<pair<int,int>> &vec,vector<vector<int>>& grid,int row0,int col0) {
        
        visited[row][col] = 1;
        vec.push_back({row-row0,col-col0});
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<4; i++) {
            
            int nr = row+dx[i];
            int nc = col + dy[i];
            
            if(nr>=0 &&nr<m && nc>=0 && nc<n &&!visited[nr][nc] && grid[nr][nc]==1) {
                visited[nr][nc]=1;
                dfs(nr,nc,visited,vec,grid,row0,col0);
            }
        }
        
        
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        set<vector<pair<int,int>>> st;
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        for(int i=0; i<m; i++) {
            
            for(int j=0; j<n; j++) {
                
                if(!visited[i][j] && grid[i][j]==1) {
                    vector<pair<int,int>> vec;
                    dfs(i,j,visited,vec,grid,i,j);
                    st.insert(vec);
                    
                }
                
            }
            
        }
        
        
        
        return st.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends