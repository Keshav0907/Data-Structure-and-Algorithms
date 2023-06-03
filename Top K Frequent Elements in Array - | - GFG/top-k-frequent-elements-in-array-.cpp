//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minH;
        unordered_map<int,int> mpp;
        vector<int> vec;
        
        for(auto x : nums) {
            mpp[x]++;
        }
        
        for(auto it: mpp) {
            minH.push({it.second,it.first});
            if(minH.size() > k) {
                minH.pop();
            }
        }
        while(!minH.empty()) {
         vec.push_back(minH.top().second);  
         minH.pop(); 
        }
        
       reverse(vec.begin(),vec.end());
        return vec;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends