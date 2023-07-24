//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        vector<int> adjList[N];
        for(auto it: edges) {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        
        vector<int> dist(N,1e9);
        
        queue<int> q;
        q.push(src);
        dist[src]=0;
        
        while(!q.empty()) {
            
            int node = q.front();
            q.pop();
            
            for(auto nbr : adjList[node]) {
                if(dist[nbr] > dist[node]+1) {
                    dist[nbr] = dist[node]+1;
                    q.push(nbr);
                }
            }
            
        }
        
        
        for(int i=0; i<N; i++) {
            if(dist[i]==1e9) dist[i]=-1;
        }
        // code here
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends