class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        
        stack<int> s;
        
        for(auto str : operations) {
            
            if(str=="D") {
                int score = s.top();
                s.push(2*score);
            } else if(str=="+") {
                int score1 = s.top();
                s.pop();
                int score2 = s.top();
                s.pop();
                s.push(score2);
                s.push(score1);
                s.push(score1+score2);
            } else if(str=="C") {
                s.pop();
            } else {
                s.push(stoi(str));
            }
                    
            
        }
        
        int ans = 0;
        while(!s.empty()) {
            cout << s.top() <<" ";
            ans += s.top();
            s.pop();
        }
        
        
        return ans;
        
        
        
        
    }
};