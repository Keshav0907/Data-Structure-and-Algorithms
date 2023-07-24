class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        
        for(int i=0; i<prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> inDegree(numCourses,0);
        
        for(int i=0; i<numCourses; i++) {
            for(auto nbr : adj[i]) {
                inDegree[nbr]++;
            }
        }
        
        queue<int> q;
        int count = 0;
        for(int i=0; i<numCourses; i++) {
            if(inDegree[i]==0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            count++;
            
            for(auto nbr : adj[front]) {
                inDegree[nbr]--;
                if(inDegree[nbr]==0) {
                    q.push(nbr);
                }
            }
            
        }
        
        
        return count==numCourses;
    }
};