class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> s;
      
        for(int i=0; i<asteroids.size(); i++) {
            
            if(asteroids[i] > 0) {
              s.push(asteroids[i]);
            } else {
                
                if(s.empty()) {
                    s.push(asteroids[i]);
                } else {
                
                while(s.size() > 0 && abs(s.top()) < abs(asteroids[i]) && s.top()>0) {
                    s.pop();
                }
                
                if(s.empty()) {
                    s.push(asteroids[i]);
                }else if(!s.empty() && abs(s.top())==abs(asteroids[i]) && s.top()>0) {
                    s.pop();
                } else if(!s.empty() && s.top() <0) {
                    s.push(asteroids[i]);
                }
              }
                   
            }
            
            
        }
        vector<int> ans(s.size(),0);
        
        for(int i=s.size()-1; i>=0; i--) {
            int res = s.top();
            ans[i] = res;
            s.pop();
        }
     
        
       
        return ans;
    }
};