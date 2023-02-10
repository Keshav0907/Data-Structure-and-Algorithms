class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        set<vector<int>> s;
     
        for(int i=0; i<=nums.size()-3; i++) {
            int j = i+1;
            int k = nums.size()-1;
            
            while(j < k) {
                int curSum = nums[i];
                curSum += nums[j];
                curSum += nums[k];
                
                if(curSum==0){
                    
                    s.insert({nums[i] , nums[j], nums[k]});
                    j++;
                    k--;
                    
                } else if(curSum > 0) {
                    k--;
                } else {
                    j++;
                }
            }     
            
        }
        
        for(auto triplets : s) {
            ans.push_back(triplets);
        }
        
       return ans; 
    }
};