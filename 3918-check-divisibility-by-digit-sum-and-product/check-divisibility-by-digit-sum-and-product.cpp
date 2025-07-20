class Solution {
public:

    int digitSum(int n)
    {
        int sum1=0;
        while(n>0)
        {
            sum1+=n%10;
            n=n/10;
        }

        return sum1;
    }


     int productSum(int n)
    {
        int sum1=1;
        while(n>0)
        {
            sum1*=n%10;
            n=n/10;
        }

        return sum1;
    }


    bool checkDivisibility(int n) {
         if (n == 0) return false; 
        int sumN=digitSum(n);
        int proN=productSum(n);

        int total=sumN+proN;

        return n%total == 0;
    }
};