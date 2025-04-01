class Solution {
public:

    int path(int r ,int c, vector<vector<int>>&dp)
    {

        if(r<0 || c<0)
        {
            return 0;
        }
        if(r==0 && c==0)
        {
            return 1;
        }
        if(dp[r][c]!=-1) return dp[r][c];
        
       dp[r][c]= path(r-1,c,dp)+path(r,c-1,dp);
       return dp[r][c];
    }


    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return path(m-1,n-1,dp);
    }
};