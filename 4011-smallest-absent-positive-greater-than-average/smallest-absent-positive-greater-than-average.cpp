class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n=nums.size();
        int val=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            val+=nums[i];
            mpp[nums[i]]++;
        }

        int avg=val/n;
       for(int i=1;i<=101;i++)
       {
            if(i>avg &&  mpp.find(i)==mpp.end())
            {
                return  i;
            }
       }
        return -1;
    }
};