class Solution {
public:
    
    static bool comp(const pair<int,int> &a,const pair<int,int> &b) {
        
        if(a.second==b.second) return a.first > b.first;
        
        return a.second < b.second;
        
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mpp;
        
        for(auto x : nums){
            mpp[x]++;
        }
        
        vector<pair<int,int>> vec;
        
        for(auto it : mpp) {
            vec.push_back({it.first,it.second});
        } 
        
        
        sort(vec.begin(),vec.end(),comp);
        vector<int> ans;
        for(int i=0; i<vec.size(); i++) {
            
            while(vec[i].second--) {
                ans.push_back(vec[i].first);
            }
            
        }
        
        return ans;
        
    }
};