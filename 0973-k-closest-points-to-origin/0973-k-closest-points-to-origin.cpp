class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
     
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>> maxH;
        
        for(int i=0; i<points.size(); i++) {
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            
            maxH.push({dist,{points[i][0],points[i][1]}});
            
            if(maxH.size() > k) {
                maxH.pop();
            }            
        }
        
        vector<vector<int>> ans(k,vector<int>(2,0));
        int i=0;
        while(!maxH.empty()) { 
            
            ans[i][0] = maxH.top().second.first;
            ans[i][1] = maxH.top().second.second;
            i++;
            maxH.pop();
            
        }
        
        return ans;
    }
};