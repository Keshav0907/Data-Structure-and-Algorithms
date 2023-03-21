class Solution {
public:
    void f(vector<int>&ans,vector<vector<int>>&res,vector<int>&v,int i,int k)
    {
        if(ans.size()==k)
        {
            res.push_back(ans);
            return;
        }
        if(i==v.size()) {
            return;
        }
        ans.push_back(v[i]);
        f(ans,res,v,i+1,k);
        ans.pop_back();
        f(ans,res,v,i+1,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        vector<vector<int>>res;
        vector<int>v;
        for(int i=0;i<n;i++)
            v.push_back(i+1);
        f(ans,res,v,0,k);
        return res;
    }
};