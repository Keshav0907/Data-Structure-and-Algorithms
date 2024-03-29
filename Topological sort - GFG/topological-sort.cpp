//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    private :
    
    void dfs(int node,vector<int> &visited,stack<int> &s,vector<int> adj[]) {
        
        visited[node]=true;
        
        
        for(auto nbr : adj[node]) {
            
        if(!visited[nbr]) {
            dfs(nbr,visited,s,adj);
        }    
        
            
        }

        s.push(node);
        
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	     vector<int> inDegrees(V,0);
	     queue<int> q;
	     for(int i=0; i<V; i++) {
	         
	         for(auto nbr : adj[i]) {
	             
	             inDegrees[nbr]++;
	             
	         }
	         
	     }
	     
	     for(int i=0; i<V; i++) {
	         
	         if(inDegrees[i]==0) {
	             q.push(i);
	         }
	         
	     }
	     
	     vector<int> ans;
	     
	     while(!q.empty()) {
	         
	         int node = q.front();
	         ans.push_back(node);
	         q.pop();
	         
	         for(auto nbr : adj[node]) {
	             inDegrees[nbr]--;
	             if(inDegrees[nbr]==0) {
	                 q.push(nbr);
	             }
	         }
	         
	         
	     }
	     
	     return ans;
	
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends