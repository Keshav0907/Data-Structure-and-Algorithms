class Solution {
public:
    string removeKdigits(string num, int k) {
    
        int n = num.length();
        if(k >= n) return "0";
        
        int count = k;
        stack<char> s;
        for(int i=0; i<num.length(); i++) {
            
            while(!s.empty() && count>0 && s.top()>num[i]){
                s.pop();
                count--;
            }
            s.push(num[i]);
        }
        
        // while(s.size()!=n-k) s.pop();
        
        while(count > 0){
            s.pop();
            count--;
        }
        
        string res = "";
        while(!s.empty()) {
            res += s.top();
            s.pop();
        }
        
        reverse(res.begin(),res.end());
        
        while (res[0] == '0') res.erase(0 , 1);
        
        return res=="" ? "0" : res;
        
    }
};


 