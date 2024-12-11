class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<bool>>isVisit(n,vector<bool>((1<<n),false));
        queue<pair<int,int>>q;
        int last =(1<<n)-1;

        for(int i=0;i<n;i++)
        {
            int travel=1<<i;
            q.push({i,travel});
            isVisit[i][travel]=true;
        }
        int first=0;
        while(!q.empty())
        {
            int s=q.size();

            for(int i=0;i<s;i++)
            {
                auto[node,mask]=q.front();
                q.pop();

            if(mask==last)
            {
                return first;
            }
            for(auto near : graph[node])
            {
                int travels= mask|(1<<near);
                if(!isVisit[near][travels])
                {
                    isVisit[near][travels]=true;
                    q.push({near,travels});
                }
            } 
            }
            first++;
        }
        return first;
    }
};