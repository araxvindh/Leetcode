class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }

        int row[]={-1,1,0,0};
        int col[]={0,0,-1,1};
        while(!q.empty())
        {
            int r1=q.front().first;
            int c1=q.front().second;

            q.pop();

            for(int i=0;i<4;i++)
            {
                int r=row[i]+r1;
                int c=col[i]+c1;

                if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1 && vis[r][c]==0)
                {
                    q.push({r,c});
                    vis[r][c]=1;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};