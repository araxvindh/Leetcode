class Solution {
public:

    static bool comp(string &a ,string &b)
    {
        return a.size()<b.size();
    }

    bool comparestr(string &a,string &b)
    {
        if(a.size()!=b.size()+1) return false;

        int first=0;
        int last=0;

        while(first<a.size())
        {
            if(a[first]==b[last])
            {
                first++;
                last++;
            }
            else
            {
                first++;
            }
        }
            if(first==a.size() && last==b.size()) return true;

            return false;
    }


    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(), comp);
        int n=words.size();

        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(comparestr(words[i],words[j])&& dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    maxi=max(dp[i],maxi);
                }
            }
        }

        return maxi;
        
    }
};