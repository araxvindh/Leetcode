class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        bool flag=true;

        if(nums[1]<=nums[0]) return false;

        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]==nums[i]) return false;

            if(flag && nums[i+1]>nums[i])
            {
                flag=false;
                cnt++;
            }

            if(!flag && nums[i+1]<nums[i])
            {
                flag=true;
                cnt++;
            }
        }
        return cnt==3;
    }
};