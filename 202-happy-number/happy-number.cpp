class Solution {
public:

    int findNumber(int n)
    {
        int num=0;

        while(n!=0)
        {
            int nNum=n%10;
            num+=nNum*nNum;
            n=n/10;
        }

        return num;
    }


    bool isHappy(int n) {
        unordered_set<int>vis;

        while(n!=1 && !vis.count(n))
        {
            vis.insert(n);
            n=findNumber(n);
        }

        return n==1;
    }
};