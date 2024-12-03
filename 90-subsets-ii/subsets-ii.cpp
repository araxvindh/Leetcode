class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>ans;
        for(int i=0;i<(1<<n);i++)
        {
            vector<int>subset;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    subset.push_back(nums[j]);
                }
            }
            ans.insert(subset);
        }
        vector<vector<int>>ans1(ans.begin(),ans.end());
        return ans1;
    }
};