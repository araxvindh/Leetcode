class Solution {

private:
    bool dfs(vector<vector<int>>&graph ,vector<int>&color ,int V ,int start,int col)
    {
        color[start]=col;

        for(auto it : graph[start])
        {
            if(color[it]==-1)
            {
                if(dfs(graph,color,V,it,!col)==false) return false;
            }
            else if(color[it]==color[start])
            {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        // dfs approch
        int V=graph.size();
        vector<int>color(V,-1);
        for(int i=0;i<V;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(graph,color,V,i,0)==false) return false;
            }
        }
        return true;
    }
};