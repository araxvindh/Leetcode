class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for (int ctr = 0; ctr < (1 << n); ctr++) {
            vector<int> subset;
            for (int shift = 0; shift < n; shift++) {
                if (ctr & (1 << shift)) {
                    subset.push_back(nums[shift]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};