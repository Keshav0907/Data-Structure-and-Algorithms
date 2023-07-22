int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

class Solution {
public:
    
    void dfs(int row,int col,vector<vector<int>> &visited,vector<vector<char>>& board) {
        
        visited[row][col] = 1;
        
        for(int i=0; i<4; i++) {
            
            int nr = row + dx[i];
            int nc = col + dy[i];
            
            if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && !visited[nr][nc] && board[nr][nc]=='O') {
                dfs(nr,nc,visited,board);
            }
            
        }
        
        
    }
    
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        for(int j=0; j<n; j++) {
            if(board[0][j]=='O' && !visited[0][j]) {
                dfs(0,j,visited,board);
            }
        }
        
        for(int j=0; j<n; j++) {
            
            if(board[m-1][j]=='O' && visited[m-1][j]==0) {
                dfs(m-1,j,visited,board);
            }
            
        }
        
        for(int i=0; i<m; i++) {
            if(board[i][0]=='O' && !visited[i][0]) {
                dfs(i,0,visited,board);
            }
        }
        
        for(int i=0; i<m; i++) {
            if(board[i][n-1]=='O' && !visited[i][n-1]) {
                dfs(i,n-1,visited,board);
            }
        }
        
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                
                if(!visited[i][j]) {
                    board[i][j] = 'X';
                }
                
            }
        }
        
        
    }
};