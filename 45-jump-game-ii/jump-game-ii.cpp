class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int maxi = 0;
        int n = nums.size();
        int j = 0;
        for(int i = 0; i < n; i++){
            if(i > j){
                ans++;
                j = maxi;
            }
            if(maxi < i + nums[i])maxi = i + nums[i];
        }

        // cout<<ans<<endl;
        return ans;
    }
};