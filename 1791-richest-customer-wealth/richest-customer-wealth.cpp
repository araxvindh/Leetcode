class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n=accounts.size();
        int m=accounts[0].size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {

            int sum1=0;
            for(int j=0;j<m;j++)
            {
                sum1+=accounts[i][j];
            }
            maxi=max(sum1,maxi);
        }

        return maxi;
    }
};