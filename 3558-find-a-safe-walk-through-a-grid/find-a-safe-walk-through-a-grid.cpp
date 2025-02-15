class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>maxHealth(n,vector<int>(m,INT_MIN));
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({health-grid[0][0],{0,0}});
        maxHealth[0][0]=health-grid[0][0];
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        while(!pq.empty())
        {
            int curr=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1 &&c==m-1 && curr>=1) return true;

            for(int i=0;i<4;i++)
            {
                int nr=r+dx[i];
                int nc=c+dy[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    if(maxHealth[nr][nc]< (curr-grid[nr][nc]))
                    {
                       maxHealth[nr][nc]=curr-grid[nr][nc];
                       pq.push({curr-grid[nr][nc],{nr,nc}});
                    }
                }
            }

        }
        return false;
    }
};