class Solution {
public:

    int solve(int n,vector<int>&dp)
    {
        int val=0;
        if(n==0 || n==1)
        {
            return 1;
        }

        if(dp[n]!=-1)
        {
            return dp[n];
        }
       
       dp[n]=solve(n-2,dp)+solve(n-1,dp);
       
        return dp[n];

    }

    int climbStairs(int n) {

        
        vector<int>dp(n+1,-1);
      
      
      return solve(n,dp);

   
    }
};