class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();

        int i=0;

        while(i<nums.size())
        {
            int correct=nums[i]-1;
            if( nums[i]!=nums[correct])
            {
                swap(nums[i],nums[correct]);
            }
            else
            {
                i++;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
            {
                return {nums[i],i+1};
            }
        }

        return {};

    }
};