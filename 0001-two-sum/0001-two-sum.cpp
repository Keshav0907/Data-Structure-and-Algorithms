class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        
        // for(int i = 0 ;i < nums.size() ; i++ ){
        //     for(int j = i+1 ; j< nums.size() ;j++){
        //         if(nums[i]+nums[j]==target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //              break;
        //         }
        //     }
        // }
        
        unordered_map<int,int> mpp;
        
        for(int i=0; i<nums.size(); i++) {
            
            if(mpp.find(target-nums[i])!=mpp.end()) {
                ans.push_back(i);
                ans.push_back(mpp[target-nums[i]]);
            } else {
                mpp[nums[i]] = i;
            }
            
        }
        
        return ans;
    }
 
};