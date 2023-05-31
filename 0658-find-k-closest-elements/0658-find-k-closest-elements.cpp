class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
//         priority_queue<pair<int,int>> maxh;
//         vector<int> ans;
//         for(int i=0; i<arr.size(); i++) {
            
//             int ele = abs(arr[i] - x);
//             maxh.push({ele,arr[i]});
//             if(maxh.size()>k) {
//                 maxh.pop();
//             }
//         }
        
//         while(maxh.size()!=0) {
//             ans.push_back(maxh.top().second);
//             maxh.pop();
//         }
        
//         // sort(ans.begin(),ans.end());
//         return ans;
        
        int L = 0, R = size(arr)-1;
        while (R - L >= k) 
            if (x - arr[L] <= arr[R] - x) R--;
            else L++;
        return vector<int>(begin(arr) + L, begin(arr) + R + 1);
    
    }
};