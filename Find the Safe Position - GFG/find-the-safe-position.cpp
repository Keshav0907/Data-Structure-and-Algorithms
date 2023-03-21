//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  void solve(vector<int> vec,int k,int index,int &ans) {
      
      if(vec.size()==1) {
          ans = vec[0];
          return;
      }
      
      index = (index + k) % vec.size();
      vec.erase(vec.begin()+index);
      solve(vec,k,index,ans);
      
  }
  
  
    int safePos(int n, int k) {
        // code here
        int index = 0;
        int ans = 0;
        vector<int> vec;
        for(int i=1; i<=n; i++) {
            vec.push_back(i);
        }
        solve(vec,k-1,index,ans);
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends