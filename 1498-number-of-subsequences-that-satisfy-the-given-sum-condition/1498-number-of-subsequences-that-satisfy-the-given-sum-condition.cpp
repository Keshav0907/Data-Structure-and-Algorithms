#define mod 1000000007
class Solution {
public:
    
int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
       
        vector<int> poww(n+1, 1);
        for(int i = 1; i<poww.size(); i++){
            poww[i] = (2*poww[i-1])%mod;
        }
        
        int cnt = 0;
        sort(nums.begin(), nums.end());
        int s = 0, e = n-1;
        while(s <= e){
            if(nums[s] + nums[e] <= target){
                cnt = (cnt+poww[e-s]) % mod;
                s++;
            }
            else e--;
        }
        return cnt;
    }
};