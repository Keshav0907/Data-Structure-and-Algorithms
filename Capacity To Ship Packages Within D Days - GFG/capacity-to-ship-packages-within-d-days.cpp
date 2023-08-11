//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    bool isPossible(int arr[],int N,int D,int threshold) {
        
        int sum = 0;
        int cnt = 1;
        
        for(int i=0; i<N; i++) {
            
            sum += arr[i];
            if(sum > threshold) {
                sum = arr[i];
                cnt++;
            }
        }
        return cnt <= D;
        
    }
  
  
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int sum = 0;
        int maxi = INT_MIN;
        
        for(int i=0; i<N; i++) {
            sum += arr[i];
            maxi = max(arr[i],maxi);
        }
        
        int low = maxi;
        int high = sum;
        int res = -1;
        
        while(low <= high) {
            
            int mid = low + (high-low)/2;
            
            if(isPossible(arr,N,D,mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends