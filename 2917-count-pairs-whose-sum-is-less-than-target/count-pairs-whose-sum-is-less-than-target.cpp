class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0;
        int high=n-1;
        int cnt=0;
        while(low<high)
        {
            if(nums[low]+nums[high]<target)
            {
                cnt+=(high-low);
                low++;
            }
            else
            {
                high--;
            }
        }
        return cnt;
    }
};