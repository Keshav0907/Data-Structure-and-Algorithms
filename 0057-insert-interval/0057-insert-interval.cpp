class Solution {
public:
    
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        vector<int> tempInterval = intervals[0];
        
        for(int i=1; i<intervals.size(); i++) {
            
            if(tempInterval[1]>=intervals[i][0]) {
                tempInterval[1]=max(tempInterval[1],intervals[i][1]);
            } else {
                merged.push_back(tempInterval);
                tempInterval = intervals[i];
            }
            
            
        }
        merged.push_back(tempInterval);
        return merged;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};