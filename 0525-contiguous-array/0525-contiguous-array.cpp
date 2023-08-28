class Solution {
public:
    
    int maxWindow(vector<int> nums,int k) {
       
        int sum = 0;
        int ans = 0;
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        
        for(int i=0; i<nums.size(); i++) {
            
            sum += nums[i];
            
            if(mpp.find(sum-k)!=mpp.end()) {
                ans = max(ans,i-mpp[sum-k]);
            } 
            
            if(mpp.find(sum)==mpp.end()) {
                mpp[sum] = i;
            }
            
        }
       
        return ans;
    }
   
    
    int findMaxLength(vector<int>& nums) {
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) nums[i]=-1;
        }
        
        return maxWindow(nums,0);
    }
};