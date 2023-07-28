class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0) {
            return 0;
        }
        
       unordered_set<int> st;
        
        for(auto x : nums) {
            st.insert(x);
        }
        
        int longest = 1;
        
        for(auto it: st) {
            int len = 1;
            if(st.find(it-1)==st.end()) {
            int nextNum = it+1;
            while(st.find(nextNum)!=st.end()) {
                nextNum++;
                len++;
            }
        }
            longest = max(longest,len);
        }

        return longest;
        
    }
};