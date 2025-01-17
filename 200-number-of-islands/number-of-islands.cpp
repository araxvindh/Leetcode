class Solution {
public:

    void bfs(vector<vector<char>>&grid , vector<vector<int>>&vis,int n,int m,int row,int col)
    {
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});

        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            int rowA[]={-1,1,0,0};
            int colA[]={0,0,-1,1};
            for(int i=0;i<4;i++)
            {
                int newR=rowA[i]+r;
                int newC=colA[i]+c;
                if(newR>=0 && newR<n && newC>=0 && newC<m && grid[newR][newC]=='1' &&vis[newR][newC]==0)
                {
                    q.push({newR,newC});
                    vis[newR][newC]=1;
                }
            }

        }
    }


    int numIslands(vector<vector<char>>& grid) {
        //bfs approach
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    cnt++;
                    bfs(grid,vis,n,m,i,j);
                }
            }
        }
        return cnt;
    }
};