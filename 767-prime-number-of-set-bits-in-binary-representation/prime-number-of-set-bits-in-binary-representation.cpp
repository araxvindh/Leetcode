class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int  np=0;
        for(int i=left;i<=right;i++)
        {
            int n=(__builtin_popcount(i));
            bool flag=true;
            for(int j=2;j<=sqrt(n);j++)
            {
                if(n%j==0 && n!=j)
                {
                    flag=false;
                }
            }
            if(flag==true && n!=1)
            {
                np++;
            }
        }
        return np;
    }
};