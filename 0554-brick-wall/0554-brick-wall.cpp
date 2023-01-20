class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        int n = wall.size();
        unordered_map<int,int> mpp;
        
        for(int i=0; i<wall.size(); i++) {
            int prefixSum = 0;
            for(int j=0; j<wall[i].size(); j++) {
                
                prefixSum += wall[i][j];
                mpp[prefixSum]++;
                
            }
            
        }
        
        int width = wall[0].size();
        int sum = 0;
        
        for(int i=0; i<width; i++) {
            sum += wall[0][i];
        }
        
        int maxi = INT_MIN;
        // mpp[0] = 0;
        mpp[sum] = 0;
        
        for(auto it: mpp) {
            maxi = max(maxi,it.second);
        }
        
        return n - maxi;
        
    }
};