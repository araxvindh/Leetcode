class Solution {
public:

    bool check(int n)
    {
        while(n>0)
        {
            int val =n%10;
            n=n/10;
            if(val==0) return false;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(check(i)&&check(j))
                {
                if(i+j==n) return {i,j};
                }
            }
        }
        return {};
    }
};