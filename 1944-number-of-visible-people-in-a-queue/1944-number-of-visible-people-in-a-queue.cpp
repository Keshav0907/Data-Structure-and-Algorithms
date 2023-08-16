class Solution {
public:
        
   vector<int> canSeePersonsCount(vector<int>& a) {
        int n=a.size();
        stack<int> st;
        int people;
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            people=0;
            while(!st.empty() && st.top()<a[i]){
                people++;
                st.pop();
            }
            ans[i]=people;
            if(!st.empty())ans[i]++;
            st.push(a[i]);
        }
        return ans;
    }
    

};