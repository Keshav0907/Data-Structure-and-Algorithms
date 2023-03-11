class Solution {
public:
    
//     vector<string> str;
//     unordered_map<string,int> mpp;
//     void helper(string s,int i) {
        
//         if(i==s.length()) {
//             // str.push_back(s);
//             mpp[s]++;
//             return;
//         }
        
//         // string s1;
//         if(isalpha(s[i])) {
//              s[i] = toupper(s[i]);
//         }
        
//         helper(s,i+1);
//         // string s2;
//           if(isalpha(s[i])) {
//              s[i] = tolower(s[i]);
//         }
//         helper(s,i+1);
        
//     }
    
    void solve(string ip,string op,vector<string> &str) {
        
        if(ip.length()==0) {
            str.push_back(op);
            return;
        }
        
        if(isalpha(ip[0])) {
            string op1 = op;
            string op2 = op;
            op1.push_back(tolower(ip[0]));
            op2.push_back(toupper(ip[0]));
            ip.erase(ip.begin()+0);
            solve(ip,op1,str);
            solve(ip,op2,str);
        } else {
            string op1 = op;
            op1.push_back(ip[0]);
            ip.erase(ip.begin()+0);
            solve(ip,op1,str);            
        }
        
        
    }
    
    vector<string> letterCasePermutation(string s) {
        
        // helper(s,0);
        // for(auto mp : mpp) {
        //     str.push_back(mp.first);
        // }
        // return str;
        
        vector<string> str;
        string ip = s;
        string o = "";
        
        solve(s,o,str);
        
        
        return str;
        
        
    }
};