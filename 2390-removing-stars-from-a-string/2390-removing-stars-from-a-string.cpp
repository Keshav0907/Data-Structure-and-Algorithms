class Solution {
public:
    string removeStars(string s) {
        
        
        string ans = "";
        stack<char> st;
        
        for(auto ch : s) {
            if(st.empty()){
                st.push(ch);
            } else if(ch=='*') {
                st.pop();
            } else {
                st.push(ch);
            }
        }
        
        
        
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};