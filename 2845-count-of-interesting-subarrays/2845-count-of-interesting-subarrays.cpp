class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    int n = nums.size();
    int prefix_sum = 0;
    unordered_map<int, int> count;


    count[0] = 1;
    long long result = 0;

    for (int i = 0; i < n; i++) {
        prefix_sum = (prefix_sum + (nums[i] % modulo == k ? 1 : 0)) % modulo;
        int complement = (prefix_sum - k + modulo) % modulo;
        result += count[complement];
        count[prefix_sum]++;
    }

    return result;
    }

};
