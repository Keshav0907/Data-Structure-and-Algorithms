class Solution {
    
    private :
    
    bool dfs(int node,vector<int> adjList[],vector<int> &visited,vector<int> &check,vector<int> &pathVisited) {
        
        visited[node] = true;
        pathVisited[node]=1;
        
        for(auto nbr : adjList[node]) {
            
            if(!visited[nbr]) {
                if(dfs(nbr,adjList,visited,check,pathVisited)==true) {
                    check[node]=0;
                    return true;
                }
            } else {
                
                if(pathVisited[nbr]==1) {
                    check[node]=0;
                    return true;
                }
                
            }
            
            
        }
        
        check[node]=1;
        pathVisited[node]=0;
        return false;
    
    }    
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int V = graph.size();
        vector<int> adjList[V];
        
        for(int i=0; i<V; i++) {
            for(int j=0; j<graph[i].size(); j++) {
                adjList[i].push_back(graph[i][j]);
            }
        }
        
        vector<int> visited(V,0);
        vector<int> check(V,0);
        vector<int> pathVisited(V,0);
        vector<int> ans;
        
        for(int i=0; i<V; i++) {
            
            if(!visited[i]) {
                dfs(i,adjList,visited,check,pathVisited);
            }            
        }
        
        
        for(int i=0; i<V; i++) {
            if(check[i]) {
                ans.push_back(i);
            }
        }
     
        return ans;
    }
};