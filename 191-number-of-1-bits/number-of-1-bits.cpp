class Solution {
public:
    int hammingWeight(int n) {
        int setbit=0;

        while(n!=0)
        {
            n=(n&(n-1));
            
                setbit++;
            
        }
        return setbit;
    }
};