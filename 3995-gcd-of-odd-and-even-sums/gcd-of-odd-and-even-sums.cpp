class Solution {
public:

    int findGcd(int a,int b)
    {
        if(b==0) return a;

        return findGcd(b,a%b);
    }



    int gcdOfOddEvenSums(int n) {
        int sumOdd=0;
        int sumEven=0;
        for(int i=1;i<=n*2;i++)
        {
            if(i%2==0)
            {
                sumEven+=i;
            }else
            {
                sumOdd+=i;
            }
        }

        return findGcd(sumOdd,sumEven);
    }
};