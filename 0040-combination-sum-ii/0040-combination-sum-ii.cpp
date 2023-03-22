class Solution {
public:
    
   
    
    void solve(vector<int> arr,int target,int i,vector<int> &op,set<vector<int>> &s) {
        
        if(target==0) {
            s.insert(op);
            return;
        }
        
        if(target <0 || i==arr.size()) {
            return;
        }
        
        op.push_back(arr[i]);
        solve(arr,target-arr[i],i+1,op,s);
        op.pop_back();
       while(i<arr.size()-1 && arr[i]==arr[i+1])
       i++;
        solve(arr,target,i+1,op,s);
        
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        
        vector<int> op;
        sort(candidates.begin(),candidates.end());
        set<vector<int>> s;
        solve(candidates,target,0,op,s);
   
        
        for(auto x : s)  {
            res.push_back(x);
        }      
        return res;
    }
};