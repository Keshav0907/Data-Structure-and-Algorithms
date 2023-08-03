class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        unordered_set<char> st;
        int result = 0;
        for(auto ch : jewels) {
            st.insert(ch);
        }
        
        for(auto ch : stones) {
            
            if(st.find(ch)!=st.end()) {
                result++;
            }
            
        }
        
        return result;
        
    }
};