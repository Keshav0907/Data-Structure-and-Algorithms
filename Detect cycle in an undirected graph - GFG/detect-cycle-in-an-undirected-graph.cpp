//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    bool detectCycle(int src,vector<int> &visited,vector<int> adj[]) {
        
        visited[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        
        while(!q.empty()) {
            
            int n = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            for(auto node : adj[n]) {
                if(!visited[node]) {
                    visited[node]=1;
                    q.push({node,n});
                } else {
                    
                    if(node!=parent) {
                        return true;
                    }
                    
                }
            }
            
        }
        
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                if(detectCycle(i,visited,adj)) {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends