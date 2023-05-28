//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    unordered_map<int,int> mpp;
	    
	    for(auto ch : pat) {
	        mpp[ch]++;
	    }
	    
	    int count = mpp.size();
	    int ans = 0;
	    
	    
	    int i=0;
	    int j=0;
	    
	    while(j < txt.size()) {
	        
	        if(mpp.count(txt[j])) {
	            mpp[txt[j]]--;
	            if(mpp[txt[j]]==0) {
	                count--;
	            }
	        }
	        
	        if(j-i+1==pat.size()) {
	            if(count==0) {
	                ans++;
	            }
	            if(mpp.count(txt[i])) {
	                mpp[txt[i]]++;
	                if(mpp[txt[i]]==1) {
	                    count++;
	                }
	            }
	            i++;
	        }
	        
	        j++;
	    }
	    
	    
	    
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends