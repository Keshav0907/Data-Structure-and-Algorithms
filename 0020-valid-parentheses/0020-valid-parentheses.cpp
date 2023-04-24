class Solution {
public:
    bool isValid(string s) {
     
        stack<char> st;
        
        
        for(auto ch: s) {
            
            switch(ch) {
               
                case '(':
                    st.push(ch);
                    break;
                case '{':
                    st.push(ch);
                    break;
                case '[':
                    st.push(ch);
                    break;
                case ')' :
                    if(!st.empty() && st.top()=='(')
                    st.pop();
                    else
                        return false;
                    break;
                case '}' :
                    if(!st.empty() && st.top()=='{')
                    st.pop();
                    else
                        return false;
                    break;
                case ']' :
                    if(!st.empty() && st.top()=='[')
                    st.pop();
                    else
                        return false;
                    break;
                default:
                    break;
            }
            
           
        }
        
        
        return st.size()==0;
     
        
    }
};