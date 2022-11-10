//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
long long SubInversionCounter(long long H[],long long low,long long mid,long long high)
    {
        long long inversions=0;
     
            long long p=low;
            long long q=mid+1;
            long long ans[high-low];
            long long k=0;
            
            while(p<=mid && q<=high)
            {
                
                if(H[p]<=H[q])
                {
                    ans[k++]=H[p++];
                }
                else
                {
                    ans[k++]=H[q++];
                    inversions+=mid-p+1;
                }
            }
    
            while(p<=mid)
            {
                ans[k++]=H[p++];
            }
    
            while(q<=high)
            {
                ans[k++]=H[q++];
            }
    
            for(long long i=0;i<k;i++)
            {
                H[low+i]=ans[i];
            }
        
        return inversions;
    }
    
    long long InversionCounter(long long H[],long long low,long long high)
    {
        long long inversionCount=0;
        if(low<high)
        {
            long long mid=((low+high)/2);
            inversionCount+=InversionCounter(H,low,mid);
            inversionCount+=InversionCounter(H,mid+1,high);
            inversionCount+=SubInversionCounter(H,low,mid,high);
        }
        return inversionCount;
    }

    long long inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        return InversionCounter(arr,0,n-1);
    }
        
     
            
   

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends