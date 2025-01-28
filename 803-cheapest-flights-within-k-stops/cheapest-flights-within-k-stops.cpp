class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<pair<int, int>>> adj(n);

         for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<int>dis(n,1e9);
        queue<pair<int,pair<int,int>>>pq;
        dis[src]=0;
        pq.push({0,{src,0}});

        while(!pq.empty())
        {
            auto it=pq.front();
            pq.pop();

            int stop=it.first;
            int node=it.second.first;
            int dist=it.second.second;
            if(stop>k) continue;
            for(auto it :adj[node])
            {
                int adjNode=it.first;
                int cost=it.second;

                if(dist+cost<dis[adjNode] && stop<=k)
                {
                    dis[adjNode]=dist+cost;
                    pq.push({stop+1,{adjNode,dist+cost}});
                }
            }
        }
        if(dis[dst]==1e9) return -1;

        return dis[dst];
    }
};