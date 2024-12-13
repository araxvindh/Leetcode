class Solution {
public:
    int oddsub(vector<int>&nums,int k)
    {
        int n=nums.size();
        if(k<0) return 0;
        int sum=0;
        int cnt=0;
        int left=0;
        int right=0;
        while(right<n)
        {
            sum+=(nums[right]%2);

            while(sum>k)
            {
                sum-=(nums[left]%2);
                left++;
            }
            right++;
            cnt+=(right-left+1);
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return oddsub(nums,k)-oddsub(nums,k-1);
    }
};