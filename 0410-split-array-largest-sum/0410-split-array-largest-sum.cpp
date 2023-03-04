class Solution {
public:
    
    bool canSplit(vector<int> nums,int k,int mid) {
      
        int sum = 0;
        int cnt = 1;
        
        for(int i=0; i<nums.size(); i++) {
            
            sum += nums[i];
            if(sum > mid){
                cnt++;
                sum = nums[i];
            }
            
            
            
        }
        if(cnt > k) {
                return false;
            }
            
        
        return true;
        // return cnt==k;
        
    }
    
    int splitArray(vector<int>& nums, int k) {
        
        int maxi = INT_MIN;
        int sum = 0;
        
        for(int i=0; i<nums.size(); i++) {
            maxi = max(maxi,nums[i]);
            sum += nums[i];
        }
        
        int start = maxi;
        int end = sum;
        int ans = -1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            
            if(canSplit(nums,k,mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                 start = mid + 1;
            }
            
        }
        
        
        return ans;
        
    }
};