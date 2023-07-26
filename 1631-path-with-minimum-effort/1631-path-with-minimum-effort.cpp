class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
              priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> effort(m,vector<int>(n,1e9));
        
        pq.push({0,{0,0}});
        effort[0][0]=0;
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        
        while(!pq.empty()) {
            
            auto it = pq.top();
            pq.pop();
            int eff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row==m-1 && col==n-1) return eff;
            
            for(int i=0; i<4; i++) {
                
                int nr = row + dx[i];
                int nc = col + dy[i];
                
                if(nr>=0 && nc<n && nr<m && nc>=0) {
                    
                    int newEff = abs(heights[row][col]-heights[nr][nc]);
                    newEff = max(newEff,eff);
                    
                    if(newEff <  effort[nr][nc]) {
                        effort[nr][nc] = newEff;
                        pq.push({newEff,{nr,nc}});
                    }
                    
                  
                }
                 
            }
            
            
        }
        
        
        return effort[m-1][n-1];
    }
};