//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    private :
    
    bool cycleCheck(int i,vector<int> &visited,vector<int> &pathVisited,vector<int> adj[]) {
        
        visited[i]=1;
        pathVisited[i]=1;
        
        for(auto it : adj[i]) {
            
            if(!visited[it]) {
                if(cycleCheck(it,visited,pathVisited,adj)==true) {
                    return true;
                }
            } else {
                
                if(pathVisited[it]){
                    return true;
                }
                
            }
            
        }
        
        
        pathVisited[i]=0;
        return false;
        
        
        
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,0);
        vector<int> pathVisited(V,0);
        
        for(int i=0; i<V; i++) {
            
            if(!visited[i]) {
                
                if(cycleCheck(i,visited,pathVisited,adj)) {
                    return true;
                }
                
            }
            
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends