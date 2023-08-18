class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int ans = 0;
        
        for(auto str : operations) {
            
            if(str=="--X" || str=="X--") {
                ans -=1;
            } else if(str=="++X" || str=="X++") {
                ans+=1;
            }
            
        }
        
        return ans;
        
    }
};