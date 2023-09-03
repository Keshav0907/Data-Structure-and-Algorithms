class Solution {
public:
    int minimumOperations(vector<int>& nums) {
    
        int n = nums.size();
        vector<int> arr(n,1);
        
        int max = 0;
        
        
        for(int i=0; i<n; i++) {

            for(int j=0; j<i; j++) {
                
                if(nums[j]<=nums[i] && 1+arr[j]>arr[i])  {
                  arr[i] = 1 + arr[j];
                }
         
            }
          
              if(arr[i] > max) max=arr[i]; 
        }
        
        return n-max;
    }
};