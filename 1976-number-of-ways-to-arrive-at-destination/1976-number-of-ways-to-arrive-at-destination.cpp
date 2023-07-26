class Solution {
    int mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto road: roads){
            int u = road[0], v = road[1], w = road[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long> dist(n,1e15);
        vector<int> ways(n,0);
        ways[0]=1;
        dist[0]=1;
        pq.push({0,0});
        
        while(!pq.empty()) {
            
            auto it = pq.top();
            pq.pop();
            long long distance = it.first;
            int node = it.second;
            
            for(auto nbr : adj[node]) {
                
                int edgeWeight = nbr.second;
                
                if(distance + edgeWeight < dist[nbr.first]) {
                    dist[nbr.first] = edgeWeight + distance;
                    pq.push({edgeWeight + distance,nbr.first});
                    ways[nbr.first] = ways[node];
                } else if(distance + edgeWeight == dist[nbr.first]) {
                    ways[nbr.first] = (ways[nbr.first] + ways[node])%mod;
                }
                
            }
            
        }
        
        return ways[n-1]%mod;
    }
};