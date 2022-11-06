//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array


    
class Solution{
  public:
    int minJumps(int arr[], int n){
        int k=0,c=0,i=0;
        if(n<=1)
      {
          return 0;
      }
      if(arr[0]==0)
      {
          return -1;
      }
      int maxrange=arr[0],step=arr[0],jump=1;
      i=1;
      for(int i=1;i<n;i++)
      {
               if(i==n-1)
          {
              return jump;
          }
          maxrange=max(maxrange,i+arr[i]);
          step--;
          if(step==0)
          {
              jump++;
                if(i>=maxrange)
              {
                  return -1;
              }
              step=maxrange-i;
          }
        
      }
      return -1;
            // while(k<n-1)
            // {
            //      k+=arr[i];
            //     c+=1;
            //     i=k;
            // }
            // return c;
        // Your code here
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends