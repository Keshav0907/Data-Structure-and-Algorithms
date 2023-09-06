// class Solution {
// public:
    
//     int solve(int i,int j,vector<int> &nums) {
        
//         if(i>j) return 0;
//         int takeI = nums[i] + min(solve(i+2,j,nums),solve(i+1,j-1,nums));
//         int takeJ = nums[j] + min(solve(i,j-2,nums),solve(i+1,j-1,nums));
    
//         return max(takeI,takeJ);
            
//     }
    
//     bool PredictTheWinner(vector<int>& nums) {
        
//         int n = nums.size();
//         int sum = 0;
//         for(auto el : nums) {
//             sum += el;
//         }
        
//         int score = solve(0,n-1,nums);
        
//         return score>=sum/2;
//     }
// };

class Solution {
public:
    int solve(vector<int> &nums,int l,int r)
    {
        if(l>r) return 0;
        int tl=nums[l]+min(solve(nums,l+2,r),solve(nums,l+1,r-1));
        int tr=nums[r]+min(solve(nums,l,r-2),solve(nums,l+1,r-1));
        return max(tl,tr);
    }
    bool predictTheWinner(vector<int>& nums) {
        int sum=0;
        for(auto it:nums) sum+=it;
        int ans=solve(nums,0,nums.size()-1);
        int ans1=sum-ans;
        return ans>=ans1;
    }
};