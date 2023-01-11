class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
//         int sum = 0;
        
//         for(int i=1; i<nums.size(); i++) {
//             sum += nums[i];
//         }
        
//         if(sum==0) {
//             return 0;
//         }
        
//         int sum2 = 0;
        
//         for(int i=nums.size()-2; i>=0; i--){
//             sum2 += nums[i];
//         }
        
//         if(sum2==0) {
//             return nums.size()-1;
//         }
        
        
        
//         for(int i=1; i<nums.size()-1; i++) {
            
//             int leftSum = 0;
//             int rightSum = 0;
            
//             for(int j=i-1; j>=0; j--) {
//                 leftSum +=nums[j];
//             }
            
//             for(int k=i+1; k<nums.size(); k++) {
//                 rightSum += nums[k];
//             }
            
//             if(leftSum == rightSum) {
//                 return i;
//             }
            
//         }
        
        int n = nums.size();
        vector<int> leftSum(n);
        vector<int> rightSum(n);
        
        leftSum[0] = 0;
        rightSum[n-1] = 0;
        
        for(int i=1; i<n; i++) {
            leftSum[i] = leftSum[i-1] + nums[i-1];
        }
        
        for(int i=n-2; i>=0; i--) {
            rightSum[i] = rightSum[i+1] + nums[i+1];
        }        
        
        
        for(int i=0; i<n; i++) {
            if(leftSum[i]==rightSum[i]) {
                return i;
            }
        }
        
        
        
        return -1;
        
        
        
        
        
    }
};