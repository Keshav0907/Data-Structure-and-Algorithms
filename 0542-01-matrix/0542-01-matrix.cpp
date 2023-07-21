class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m,vector<int>(n));
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j]==0) {
                    dist[i][j]=0;
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        while(!q.empty()){
            
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++) {
                
                int nr = row + dx[i];
                int nc = col + dy[i];
                
                if(nr>=0 && nr<m && nc>=0 && nc<n && visited[nr][nc]!=1) {
                    dist[nr][nc] = distance+1;
                    q.push({{nr,nc},distance+1});
                    visited[nr][nc]=1;
                }
                
                
            }
            
        }
        
        return dist;
    }
};