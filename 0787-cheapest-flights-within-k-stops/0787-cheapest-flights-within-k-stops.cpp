class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int,int>>adj[n];

        //CREATING LIST TO SOTRE ADJOINT LIST
        for(auto it: flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>>q;
        //creating distance vector for storing distance
        vector<int>dis(n,1e9);

        //pushing the staing index and maeking it as zero.
        q.push({0,{src,0}});
        dis[src]=0;

        //applying basic djsktra algo using relaxation;
        while(!q.empty())
        {
            auto it=q.front();
            int step=it.first;
            int node=it.second.first;
            int dist=it.second.second;
            q.pop();
             
            //CHECKING WHETER THE ABOVE STEPS NOT ACCECED THE MENTIONED NUMBER OF STEPS. 
            if(step>k)
            continue;

            for(auto iter:adj[node])
            {
                int edge=iter.first;
                int weight=iter.second;
                if(dis[edge]>weight+dist && step<=k+1)
                {
                    dis[edge]=weight+dist;
                    q.push({step+1,{edge,dis[edge]}});
                }
            }
        }

        if(dis[dst]==1e9)
        return -1;
        else
        return dis[dst];

    }
};