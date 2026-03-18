class Solution {
public:

    long long findGcd(int a ,int b)
    {
        if(b==0) return a;
        if(b>a) return findGcd(b,a);
        return findGcd(b, a%b);
    }

    long long gcdSum(vector<int>& nums) {
        
        vector<long long>prefGcd;
        int maxii=-1;
        for(auto it : nums)
        {
            maxii=max(it,maxii);
            prefGcd.push_back(findGcd(it,maxii));
        }

        // for(int i=0;i<nums.size();i++)
        // {
        //     prefGcd.push_back(findGcd(nums[i],maxii));
        // }

        sort(prefGcd.begin(),prefGcd.end());

        int i=0;
        int j=prefGcd.size()-1;
        long long cnt=0;
        while(i<j)
        {
            cnt+=findGcd(prefGcd[i],prefGcd[j]);
            i++;
            j--;
        }

        return cnt;

    }
};