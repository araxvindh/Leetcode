class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // topo sort
        vector<vector<int>> adj(numCourses);
        for(auto&it : prerequisites)
        {
            int u=it[1];
            int v=it[0];
            adj[u].push_back(v);
        }

        vector<int> indegree(numCourses, 0);

        for(int i=0;i<numCourses;i++)
        {
            for(auto it :adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>top;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            top.push_back(node);

            for(auto it : adj[node])
            {
                indegree[it]--;

                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        if(top.size()==numCourses)
        {
            return true;
        }

        return false;
    }
};