class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        
        unordered_map<double,long long> mpp;
        long long count = 0;
        
        for(int i=0; i<rectangles.size(); i++) {
            
            double ratio = (double)rectangles[i][0]/(double)rectangles[i][1];
            if(mpp.find(ratio)==mpp.end()) {
                mpp[ratio]++;
            } else {
                count += mpp[ratio];
                mpp[ratio]++;
            }
            
            
        }
        
        return count;
        
    }
};

// class Solution {
// public:
//     long long interchangeableRectangles(vector<vector<int>>& rectangles) {
//         int n = rectangles.size();
//         long long ans = 0;
//         unordered_map<double, long long> mp;
//         for(int i = 0; i < n; i++){
//             double r = (double)rectangles[i][0] / rectangles[i][1];
//             if(mp.find(r) != mp.end()){
//                 ans += mp[r];
//             }
//             mp[r]++;
//         }
//         return ans;
//     }
// };