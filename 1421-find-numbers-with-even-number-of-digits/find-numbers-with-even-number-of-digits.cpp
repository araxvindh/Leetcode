class Solution {
public:

    int sizeOf(int n)
    {
        int a=0;

        while(n>0)
        {
            a++;
            n=n/10;
        }

        return a;
    }

    int findNumbers(vector<int>& nums) {

        int n= nums.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(sizeOf(nums[i])%2==0)
            {
                cnt++;
            }
        }

        return cnt;
    }
};