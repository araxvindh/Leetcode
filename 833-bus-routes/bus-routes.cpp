class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;

        unordered_map<int,vector<int>> adjList;
        int n=routes.size();
        for(int i=0;i<n;i++)
        {
            for(auto it : routes[i])
            {
                adjList[it].push_back(i);
            }
        }

        unordered_set<int>visit;
        queue<int>q;
        q.push(source);
        int buses=0;

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int stop =q.front();
                q.pop();

                if(stop==target)
                {
                    return buses;
                }

                for(int i : adjList[stop])
                {
                    if(visit.count(i))
                    {
                        continue;
                    }

                    visit.insert(i);
                    for(int nextStop : routes[i])
                    {
                        q.push(nextStop);
                    }
                }
            }
            buses++;
        }
        return -1;
    }
};