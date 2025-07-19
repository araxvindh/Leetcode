class Solution {
public:

    void dfs(vector<vector<int>>&grid,vector<vector<int>>&mat,int r,int c,long long& tSum,int n,int m)
         {
         if(r<0 || c<0 || r>=n ||  c>=m || grid[r][c]==0 || mat[r][c]==1)
         {
            return ;
         }
            mat[r][c]=1;
            tSum+=grid[r][c];

            int row[]={-1,1,0,0};
             int col[]={0,0,-1,1};

             for(int i=0;i<4;i++)
                 {
                     dfs(grid,mat,r+row[i],c+col[i],tSum,n,m);
                 }
         

    
         }

    
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>mat(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    {
                        if(grid[i][j]!=0 && mat[i][j]==0)
                        {
                            long long tSum=0;
                            dfs(grid,mat,i,j,tSum,n,m);
                            if(tSum%k==0)
                            {
                                cnt++;
                            }
                        }
                    }
            }

        return cnt;
    }
};