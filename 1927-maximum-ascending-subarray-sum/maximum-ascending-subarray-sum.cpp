class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        int maxi=INT_MIN;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i])
            {
                sum+=nums[i];
            }
            else
            {
                maxi=max(sum,maxi);
                sum=nums[i];
            }

        }
        maxi=max(sum,maxi);

        return maxi;
    }
};