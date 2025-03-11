#define ll unsigned long long

class Solution {
public:
    int change(int value, vector<int>& coins) {
        int n=coins.size();
        vector<vector<ll>>dp(n,vector<ll>(value+1,0));

        for(int t=0;t<=value;t++)
        {
            dp[0][t]=(t%coins[0]==0);
        }

        for(int i=1;i<n;i++)
        {
            for(int t=0;t<=value;t++)
            {
                ll notPick=dp[i-1][t];
                ll pick=0;

                if(coins[i]<=t)
                {
                    pick=dp[i][t-coins[i]];
                }
                dp[i][t]=pick+notPick;
            }
        }
        return dp[n-1][value];

    }
};