// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int j = 0, odd = 0, count = 0, total = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] & 1) {
//                 odd++;
//                 if (odd >= k) {
//                     count = 1;
//                     while (!(nums[j++] & 1)) count++;
//                     total += count;
//                 }
//             } else if (odd >= k) total += count;
//         }
//         return total;
//     }
// };
class Solution {
public:
    
     int subarraySum(vector<int>& nums, int k) {
        
        
        unordered_map<int,int> mpp;
        mpp[0]=1;        
        int count = 0;
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            
            sum += nums[i];
            
            if(mpp.find(sum-k)!=mpp.end()) {
                count += mpp[sum-k];
            }
            
            mpp[sum]++;
            
        }
        
        return count;
    }
    // int subArray(vector<int>& nums, int k) {
    //     int count = 0, ans = 0, start = 0, end = 0;
    //     int n = nums.size();
    //     while(end<n){
    //         if(nums[end]%2==1){
    //             count++;
    //         }
    //         while(count>k){
    //             if(nums[start]%2==1){
    //                 count--;
    //             }
    //             start++;
    //         }
    //         ans += end-start+1;
    //         end++;
    //     }
    //     return ans;
    // }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]&1) nums[i]=1;
            else nums[i]=0;
        }
        
        return subarraySum(nums,k);
      // return subArray(nums, k) - subArray(nums,k-1);
        
    }
};
