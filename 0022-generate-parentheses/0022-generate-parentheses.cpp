class Solution {
public:
    
 void solve(int N,int i,int open,int close,vector<string> &ans,string op) {
    
    if(i==2*N) {
        ans.push_back(op);
        return;
    }
    
    
       if(open < N) {
       solve(N,i+1,open+1,close,ans,op+'('); 
      } 
    
       if(open > close){
      solve(N,i+1,open,close+1,ans,op+')');
      }
    
    
    }

    
    vector<string> generateParenthesis(int n) {
        
    vector<string> ans;
    int open = 0;
    int close = 0;
    int i=0;
    string op = "";
    solve(n,i,open,close,ans,op);
    return ans;
        
    }
};