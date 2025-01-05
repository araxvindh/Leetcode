class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> mpp;
        int diff =0;
        
        for(int i=0;i<n;i++)
        {
            if(mpp.find(nums[i]+k)!=mpp.end())
            {
                diff+=mpp[nums[i]+k];
            }
            if(mpp.find(nums[i]-k)!=mpp.end())
            {
                diff+=mpp[nums[i]-k];
            }
            mpp[nums[i]]++;
        }
        return diff;
    }
};