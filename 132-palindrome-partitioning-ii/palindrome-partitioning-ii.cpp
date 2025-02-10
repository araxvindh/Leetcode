class Solution {
public:

    bool isPallindrome(string &str,int i,int j)
{
    while(i<j)
    {
        if(str[i]!=str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}


    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        dp[n]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            int minCost=INT_MAX;
            string temp="";
            for(int j=i;j<n;j++)
            {
                temp+=s[j];

                if(isPallindrome(s,i,j))
                {
                    int cost = 1+dp[j+1];
                    minCost=min(cost,minCost);
                }

            }
                dp[i]=minCost;

        }
            return dp[0]-1;

    }
};