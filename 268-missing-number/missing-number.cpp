class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //cyclic sort 
        int ind=0;
        int n=nums.size();
        while(ind<n)
        {
            int c=nums[ind];
            if(nums[ind]<n && nums[ind]!=nums[c])
            {
                swap(nums[ind],nums[c]);
            }
            else
            {
                ind++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i)
            {
                return i;
            }
        }
        return n;
    }
};