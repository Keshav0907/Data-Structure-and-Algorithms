//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    void solve(int N,int count1,int count0,string op,vector<string> &result) {
        
        
        if(op.length()==N) {
            result.push_back(op);
            return;
        }
        
        solve(N,count1+1,count0,op+'1',result);
        if(count1>count0) {
            solve(N,count1,count0+1,op+'0',result);
        }
        
        
    }
    
   
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    vector<string> result;
	    int count1 = 0;
	    int count0 = 0;
	    string op = "";
	    solve(N,count1,count0,op,result);
	    return result;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends