class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;

        for(auto it :nums)
        {
            mpp[it]++;
        }

        int maxi=INT_MIN;

        for(auto it :mpp)
        {
            maxi=max(maxi,it.second);
        }

        int totalSum=0;
        for(auto it :mpp)
        {
            if(it.second==maxi)
            {
                totalSum+=it.second;
            }
        }

        return totalSum;
    }
};