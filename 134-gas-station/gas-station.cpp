class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int m=cost.size();
        int start=0;
        int g=0;
        int c=0;
        int sum1=0;
        for(int i=0;i<n;i++)
        {
            g+=gas[i];
            c+=cost[i];

            sum1+=gas[i]-cost[i];

            if(sum1<0)
            {
                start=i+1;
                sum1=0;
            }
        }


        return (g<c)?-1:start;
    }
};