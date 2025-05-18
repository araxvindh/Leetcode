class Solution {
public:

    int sumOfDig(int n)
    {
        int val=0;
        n=abs(n);
        while(n>0)
        {
            val+=n%10;
            n=n/10;
        }

        return val;
    }


    int smallestIndex(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            if(sumOfDig(nums[i])==i)
            {
                return i;
            }
        }

        return -1;
    }
};