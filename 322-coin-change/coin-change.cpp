class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        for(int i=0;i<=target;i++)
        {
            if(i%coins[0]==0)
            {
                dp[0][i]=i/coins[0];
            }
            else
            {
                dp[0][i]=1e9;
            }
        }

        for(int ind=1;ind<n;ind++)
        {
            for(int t=0;t<=target;t++)
            {
                int notTake=0+dp[ind-1][t];

                int take=INT_MAX;

                if(coins[ind]<=t)
                {
                    take=1+dp[ind][t-coins[ind]];
                }

                dp[ind][t]=min(take,notTake);
            }
        }

        int ans= dp[n-1][target];
        if(ans>=1e9) return -1;

        return ans;
    }
};