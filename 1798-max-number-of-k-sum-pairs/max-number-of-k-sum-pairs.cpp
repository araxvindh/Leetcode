class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0;
        int right=n-1;
        int cnt=0;
        while(left<right)
        {
            if(nums[left]+nums[right]==k)
            {
                cnt++;
                left++;
                right--;
            }
            else if(nums[left]+nums[right]>k)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return cnt;
    }
};