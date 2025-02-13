class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==1)
        {
            return 0;
        }
        int maxEl=INT_MIN;
        for(auto it :nums)
        {
            maxEl=max(maxEl,it);
        }
        int index=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]*2 >maxEl && maxEl!=nums[i])
            {
                return -1;
            }
            
            if(maxEl==nums[i])
            {
                index=i;
            }
        }

        return index;

    }
};