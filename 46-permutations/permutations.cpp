class Solution {
public:

    void perm(vector<int>&nums,vector<vector<int>>&ans,int left,int right)
    {
        if(left==right)
        {
            ans.push_back(nums);
            return;
        }
        for(int i=left;i<right;i++)
        {
            swap(nums[left],nums[i]);
            perm(nums,ans,left+1,right);
            swap(nums[left],nums[i]);
        }
    
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        perm(nums,ans,0,n);

      return ans;
    }
};