class Solution {
private:
    bool dfs(vector<vector<int>>&graph,vector<int>&vis,vector<int>&pathVis,vector<int>&check,int node)
    {
        vis[node]=1;
        pathVis[node]=1;
        check[node]=0;

        for(auto it :graph[node])
        {
            if(!vis[it])
            {
                if(dfs(graph,vis,pathVis,check,it)==true)
                {
                    check[node]=0;
                    return true;
                }
            }
                else if(pathVis[it])
                {
                    check[node]=0;
                    return true;
                }
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        vector<int>safeNode;
        vector<int>check(V,0);

        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(graph,vis,pathVis,check,i);
            }
        }

        for(int i=0;i<V;i++)
        {
            if(check[i]==1)
            {
                safeNode.push_back(i);
            }
        }

        return safeNode;
    }
};