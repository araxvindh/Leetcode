class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;

        for(auto it :nums)
        {
            if(i==0||i==1||nums[i-2]!=it)
            {
                nums[i]=it;
                i++;
            }
        }
        return i;
    }
};