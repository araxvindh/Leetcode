class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        int n=responses.size();
        map<string,int>mpp;
        for(int i=0;i<n;i++)
        {
            set<string>s;
            for(auto it : responses[i])
            {
                s.insert(it);
            }

            for(auto i :s)
            {
                mpp[i]++;
            }
        }
        string ans;
        int maxi=0;
        for(auto it :mpp)
        {
            if(it.second>maxi)
            {
                maxi=it.second;
                ans=it.first;
            }
        }

        return ans;
    }
};