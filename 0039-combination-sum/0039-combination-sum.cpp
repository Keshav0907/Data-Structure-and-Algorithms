class Solution {
public:
    
    void solve(vector<int> &arr,int target,vector<int> &op,vector<vector<int>> &res,int i) {
        if(target==0){
            res.push_back(op);
            return;
        }
        
        if(i==arr.size()) {
            return;
        }
          
        //vector<int> op1 = op;
        //vector<int> op2 = op;
        if(arr[i]<=target)
        {
        op.push_back(arr[i]);
        solve(arr,target-arr[i],op,res,i);
        op.pop_back();
        }
        solve(arr,target,op,res,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> output;
        solve(candidates,target,output,res,0);
        return res;
    }
};