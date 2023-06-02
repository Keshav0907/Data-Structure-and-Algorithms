//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
  
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    vector<int> ans;
	    priority_queue<int,vector<int>,greater<int>> minH;
	    
	    for(int i=0; i<n; i++) {
	        
	        minH.push(arr[i]);
	        
	        if(minH.size() > k){
	            minH.pop();
	        }
	        
	    }
	    
	    
	    while(!minH.empty()) {
	        ans.push_back(minH.top());
	        minH.pop();
	    }
	    sort(ans.begin(),ans.end(),greater<int>());
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends