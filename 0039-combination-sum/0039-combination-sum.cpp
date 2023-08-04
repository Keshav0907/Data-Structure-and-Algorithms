class Solution {
public:
    
//     void solve(vector<int> &arr,int target,vector<int> &op,vector<vector<int>> &res,int i) {
// //         if(target==0){
// //             res.push_back(op);
// //             return;
// //         }
        
// //         if(i==arr.size()) {
// //             return;
// //         }
          
// //         // vector<int> op1 = op;
// //         // vector<int> op2 = op;
// //         if(arr[i]<=target)
// //         {
// //         op.push_back(arr[i]);
// //         solve(arr,target-arr[i],op,res,i);
// //         op.pop_back();
// //         }
// //         solve(arr,target,op,res,i+1);
        
        
//     }
    
void solve(vector<int> arr,int n,int k,vector<int> ans,vector<vector<int>> &res) {
    
    if(k==0) {
        res.push_back(ans);
        return;
    }
    if(k < 0) return;
    if(n==0) {
        return;
    }
    
    ans.push_back(arr[n - 1]);
    solve(arr, n , k - arr[n - 1], ans, res);
    ans.pop_back();
    solve(arr,n-1,k,ans,res);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> output;
        // solve(candidates,target,output,res,0);
        solve(candidates,candidates.size(),target,output,res);
        return res;
    }
};