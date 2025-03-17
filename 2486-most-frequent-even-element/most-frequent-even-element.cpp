class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                mpp[nums[i]]++;
            }
        }
        int maxi=INT_MIN;
        int ele=-1;
        for(auto it :mpp)
        {
            if(it.second>maxi)
            {
                maxi=it.second;
                ele=it.first;
            }
            else if(maxi==it.second)
            {
                ele=min(ele,it.first);
            }
        }

        return ele;
    }
};