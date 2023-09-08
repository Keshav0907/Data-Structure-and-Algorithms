class Solution {
public:
    string removeDuplicateLetters(string s) {
         
        vector<int> freq(26,0);
        vector<bool> visited(26,false);
        stack<char> st;
        string ans = "";
        
        for(auto ch : s) {
            freq[ch-'a']++;
        }
        
        
        for(int i=0; i<s.length(); i++) {
            
            if(visited[s[i]-'a']) {
                freq[s[i]-'a']--;
                continue;
            }
            
            while(!st.empty() && st.top()>s[i] && freq[st.top()-'a']>0) {
                visited[st.top()-'a']=false;
                st.pop();
            }
            
            st.push(s[i]);
            freq[s[i]-'a']--;
            visited[s[i]-'a'] = true;
        }
        
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};