class Solution {
public:
    
     static bool compare(string &a,string &b) {
                
         return a+b > b+a;
        
    }
    
    string largestNumber(vector<int>& nums) {
        
        vector<string> s;

		for(auto i:nums){
            
		   string str= to_string(i);
	       s.push_back(str);
            
		}

		sort(s.begin(),s.end(),compare);
        
        
        if(s[0]=="0") {
            return "0";
        }
        
        string ans = "";
        
        for(auto x : s) {
            
            ans += (x);
            
        }
        
        
        return ans;
        
    }
};