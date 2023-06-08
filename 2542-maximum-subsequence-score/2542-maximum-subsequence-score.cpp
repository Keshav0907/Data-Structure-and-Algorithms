class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
     
        vector<pair<int,int>> vec;
        
        for(int i=0; i<nums1.size(); i++) {
            vec.push_back({nums2[i],nums1[i]});
        }
        
        sort(vec.rbegin(),vec.rend());
        long long ans = 0;
        long long sum = 0;
        priority_queue<int,vector<int>,greater<int>> minH;
        for(int i=0; i<k; i++) {
          sum += vec[i].second;  
          minH.push(vec[i].second);
        }
        
        ans = sum*vec[k-1].first;
        for(int i=k; i<nums1.size(); i++) {
            
            sum += vec[i].second;
            sum -=minH.top();
            minH.pop();
            minH.push(vec[i].second);
            
            ans = max(ans,sum*vec[i].first);            

        }
        
     return ans;        
        
    }
};