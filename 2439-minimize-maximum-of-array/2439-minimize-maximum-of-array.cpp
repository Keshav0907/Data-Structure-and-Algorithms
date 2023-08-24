class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long int sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(ans, (int)((sum + i) / (i + 1)));
        }
        return ans;
    }
};
