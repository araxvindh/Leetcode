class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //bfs approcah
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        //{{r,c},t};
        queue<pair<pair<int,int>,int>>q;
        int freshOrange=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(grid[row][col]==2)
                {
                    q.push({{row,col},0});
                    vis[row][col]=2;
                }
                else
                {
                    vis[row][col]=0;
                }

                if(grid[row][col]==1)
                {
                    freshOrange++;
                }
            }
        }

        int maxTime=0;
        int cnt=0;
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;

            maxTime=max(time,maxTime);
            q.pop();
            int r[]={-1,1,0,0};
            int c[]={0,0,-1,1};
            for(int i=0;i<4;i++)
            {
                int newR=r[i]+row;
                int newC=c[i]+col;

                if(newR>=0 && newR<n && newC>=0 && newC<m && grid[newR][newC]==1 && vis[newR][newC]!=2)
                {
                    q.push({{newR,newC},time+1});
                    vis[newR][newC]=2;
                    cnt++;
                }
            }
        }

        if(cnt!=freshOrange) return -1;

        return maxTime;
    }
};