class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //cyclic sort 

        int ind =0;
        int n=nums.size();
        while(ind<n)
        {
            int crt=nums[ind]-1;
            if( nums[ind]!=nums[crt])
            {
                swap(nums[ind],nums[crt]);
            }
            else
            {
                ind++;
            }

        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
            {
                ans.push_back(i+1);
            }
        }

        return ans;
    }
};