class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        set<int> st(nums.begin(),nums.end());
        
        vector<int> temp(st.begin(),st.end());
        int n = nums.size();
        int minOpr = INT_MAX;
        
        for(int i=0; i<temp.size(); i++) {
            
            int L = temp[i];
            int R = L + n - 1;
            
            int upperBound = upper_bound(temp.begin(),temp.end(),R) -temp.begin();
            
            int inRange = upperBound - i;
            
            int outRange = n-inRange;
            
            minOpr = min(minOpr,outRange);
            
        }
        
        return minOpr;
    }
};