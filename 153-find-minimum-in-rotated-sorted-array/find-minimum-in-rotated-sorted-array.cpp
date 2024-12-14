class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;

        int min1=INT_MAX;

        while(low<=high)
        {
            int mid=(low+high)/2;

            if(nums[mid]>=nums[low])
            {
                min1=min(min1,nums[low]);
                low=mid+1;
            }
            else
            {
                min1=min(min1,nums[mid]);
                high=mid-1;
            }
        }
        return min1;
    }
};