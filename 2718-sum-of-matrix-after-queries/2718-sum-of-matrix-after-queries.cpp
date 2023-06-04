class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        
        set<pair<int,int>> s;
        long long sum = 0;
        int row = n;
        int col = n;
        
        for(int i=queries.size()-1; i>=0; i--) {
            
            int type = queries[i][0];
            int flag = queries[i][1];
            int val = queries[i][2];
            
            if(s.find({type,flag})==s.end()) {
                
                s.insert({type,flag});
                if(type==0) {
                    sum += row*val;
                    col--;
                } else {
                    sum += col*val;
                    row--;
                }    
            } else {
                continue;
            }
            
        }     
        return sum;
    }
};