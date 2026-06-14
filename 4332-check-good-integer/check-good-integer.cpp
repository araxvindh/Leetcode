class Solution {
public:
    bool checkGoodInteger(int n) {
        int digSum=0;
        int x=0;
        while(n>0)
        {   
            x+=(n%10);
            digSum+=(n%10)*(n%10);
            n=n/10;
        }

        if(digSum-x >=50)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};