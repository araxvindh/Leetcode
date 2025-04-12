class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int val=0;
        for(int i=0;i<n;i++)
        {
            val+=nums[i];
        }

        return val%k;
    }
};