//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	    int ans = INT_MIN;
	    
	   // for(int i = 0; i<n-1; i++) {
	   //     if(arr[i] > arr[i+1]) {
	   //         ans = arr[i];
	   //         break;
	   //    }
	   // }
	   
	   int low = 0;
	   int high = n-1;
	   
	   while(low < high) {
	       
	       int mid = low + (high-low)/2;
	       if(arr[mid] > arr[mid+1]) {
	           ans = arr[mid];
	           high = mid;
	       } else if(arr[mid] < arr[mid+1]) {
	           low = mid+1;
	       
	   }
	   }
	    
	   // if(ans==INT_MIN) ans = arr[n-1];
	    return arr[high];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends