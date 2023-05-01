class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        if(k > s.length()) {
            return s;
        }
        for(int i=0; i<s.length(); i++) {
            
            if(st.empty()) {
                st.push({s[i],1});
            } else {
                if(st.top().first==s[i]) {
                    st.top().second += 1;
                    if(st.top().second==k)  {
                        st.pop();
                    }
                } else {
                    st.push({s[i],1});
                }
            }
        }
        
        string res = "";
        
        while(!st.empty()) {
            while(st.top().second--) {
             res += st.top().first;
            }
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};