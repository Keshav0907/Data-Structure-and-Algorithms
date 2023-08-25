//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
     
    int count(vector<int> nums,int sum) {
        
        int m = nums.size();
        
        vector<vector<int>> dp(m+1,vector<int>(sum+1));
        
        for(int i=0; i<m+1; i++) {
            for(int j=0; j<sum+1; j++) {
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        
        for(int i=1; i<m+1; i++) {
            for(int j=0; j<sum+1; j++) {
                if(nums[i-1]<=j) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][sum];
    }
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
         int sum = 0;
        for(auto num : A) {
            sum += num;
        }
        if((sum+target)%2!=0 || sum<target) return 0;
        if((sum+target)/2<0) return 0;
        return count(A,(sum+target)/2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends