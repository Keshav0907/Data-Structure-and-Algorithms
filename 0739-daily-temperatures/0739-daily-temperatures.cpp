class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<pair<int,int>> s;
        vector<int> ans;
        int n = temperatures.size();
        for(int i=n-1; i>=0 ; i--) {
            
            while(s.size()>0  && s.top().second<=temperatures[i]) {
                s.pop();
            }
            
            if(s.size()==0){
                ans.push_back(0);
            } else {
                ans.push_back(s.top().first);
            }
            
            s.push({i,temperatures[i]});            
            
            
        }
        
        reverse(ans.begin(),ans.end());
        
        for(int i=0; i<ans.size(); i++) {
            if(ans[i]!=0){
                ans[i] = ans[i]-i;
            }
        }
            
        return ans;
        
    }
};