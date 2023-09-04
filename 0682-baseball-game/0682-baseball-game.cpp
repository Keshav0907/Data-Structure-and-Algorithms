class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        
       stack<int> s;
        
        for(auto ch : operations) {
            
    
                if(ch=="+") {
                    int first = s.top();
                    s.pop();
                    int second = s.top();
                    s.pop();
                    s.push(second);
                    s.push(first);
                    s.push(first+second);
                } else if(ch=="C") {
                    s.pop();
                } else if(ch=="D") {
                      s.push(2*s.top()); 
                }else {
                   s.push(stoi(ch)); 
                }
                

        }
        
        int sum = 0;
        while(!s.empty()) {
            cout << s.top() <<" ";
            sum += s.top();
            s.pop();
        }
       return sum; 
    }
};