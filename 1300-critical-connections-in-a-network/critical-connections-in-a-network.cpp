class Solution {
public:

    private:
    int timmer=1;
    public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& tim, vector<int>& low,
         vector<vector<int>>& bridges, int node, int parent) {
    vis[node] = 1;
    low[node] = tim[node] = timmer++;
    
    for (auto it : adj[node]) {
        if (it == parent) continue;

        if (!vis[it]) {
            dfs(adj, vis, tim, low, bridges, it, node);
            low[node] = min(low[node], low[it]);

            if (low[it] > tim[node]) {
                bridges.push_back({node, it});
            }
        } else {
            // Back edge case
            low[node] = min(low[node], tim[it]);
        }
    }
}


    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // make adj matrix
        vector<vector<int>>adj(n,vector<int>());
        for(auto it :connections)
        {
            adj[it[1]].push_back(it[0]);
            adj[it[0]].push_back(it[1]);
        }

        vector<int>vis(n,0);
        vector<int>tim(n,0);
        vector<int>low(n,0);

        vector<vector<int>>bridges;

        dfs(adj,vis,tim,low,bridges,0,-1);


        return bridges;
    }
};