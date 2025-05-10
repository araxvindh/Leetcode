class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n=nums.size();
        vector<int>odd;
        vector<int>even;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                even.push_back(nums[i]);
            }
            else
            {
                odd.push_back(nums[i]);
            }
        }

        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end(),greater<int>());

        int o=0;
        int e=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0) nums[i]=even[e++];
            else nums[i]=odd[o++];
        }


        return nums;
    }
};