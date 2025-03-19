class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),hash(n);
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
        }

        sort(nums.begin(),nums.end());

        int lastInd=0;
        int maxii=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i])
                {
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>maxii)
            {
                maxii=dp[i];
                lastInd=i;
            }
        }

        vector<int>ans;
        ans.push_back(nums[lastInd]);
        while(hash[lastInd]!=lastInd)
        {
            lastInd=hash[lastInd];
            ans.push_back(nums[lastInd]);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};