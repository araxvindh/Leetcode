class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int flag=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=nums[i+1])
            {
                flag=1;
            }
        }

        if(flag==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }

    }
};