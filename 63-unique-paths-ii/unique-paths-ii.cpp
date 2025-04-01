class Solution {
public:

    int path(int r,int c,vector<vector<int>>&dp,vector<vector<int>>&grid)
    {
        if(r<0 || c<0 || grid[r][c]==1)
        {
            return 0;
        }

        if(r==0 && c==0) return 1;

        if(dp[r][c]!=-1) return dp[r][c];

        dp[r][c]=path(r-1,c,dp,grid)+path(r,c-1,dp,grid);

        return dp[r][c];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return path(n-1,m-1,dp,obstacleGrid);
    }
};