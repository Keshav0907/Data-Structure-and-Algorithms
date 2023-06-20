class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minH;
        
        for(int i=0; i<trips.size(); i++) {
            
            minH.push({trips[i][1],trips[i][0]});
            minH.push({trips[i][2],-trips[i][0]});
            
        }
        
        while(!minH.empty()) {
            capacity -= minH.top().second;
            minH.pop();
            if(capacity < 0) {
                return false;
            }
        }
        
        return true;
    }
};