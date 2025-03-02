class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int set=0;
            int num=i;
            while(num!=0)
            {
                num=num&(num-1);
                set++;
            }
            if(set==k)
            {
                sum+=nums[i];
            }
        }
        return sum;
    }
};