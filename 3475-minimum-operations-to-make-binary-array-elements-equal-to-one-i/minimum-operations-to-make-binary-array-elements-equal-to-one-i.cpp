class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();

        int i=2;
        int cnt=0;
        while(i<n)
        {
            if(nums[i-2]==0)
            {
                nums[i-2]=!nums[i-2];
                nums[i-1]=!nums[i-1];
                nums[i]=!nums[i];
                cnt++;
            }
            i++;
        }
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=1)
            {
                flag=1;
            }
        }

     return (flag==1)?-1:cnt;
    }
};