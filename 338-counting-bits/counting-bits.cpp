class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            int set=0;
            int num=i;
            while(num!=0)
            {
                num=num&(num-1);
                set++;
            }
            ans.push_back(set);
        }
        return ans;
    }
};