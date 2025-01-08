class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        for(auto it :pre)
        {
            int u=it[1];
            int v=it[0];
            adj[u].push_back(v);
        }

        vector<int>inDegree(n,0);

        for(int i=0;i<n;i++)
        {
            for(auto it : adj[i])
            {
                inDegree[it]++;
            }
        }

        queue<int>q;

        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            topo.push_back(node);

            for(auto it : adj[node])
            {
                inDegree[it]--;

                if(inDegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        if (topo.size()==n)return topo;

        return {};
    }
};