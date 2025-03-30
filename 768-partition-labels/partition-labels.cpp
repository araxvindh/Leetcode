class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        map<char,pair<int,int>>mpp;
        
        for(int i=0;i<n;i++)
        {
            if(mpp.find(s[i])==mpp.end())
            {
                mpp[s[i]]={i,i};
            }

            mpp[s[i]].second=i;
        }
        vector<pair<int,int>>v;

        for(auto it:mpp)
        {
            v.push_back(it.second);
        }

        sort(v.begin(),v.end());

        vector<int>ans;

        int first=v[0].first;
        int end=v[0].second;

        for(int i=1;i<v.size();i++)
        {
            if(v[i].first <=end)
            {
                end=max(end,v[i].second);
            }

            else
            {
                ans.push_back(end-first+1);

                first=v[i].first;
                end=v[i].second;
            }
        }

        ans.push_back(end-first+1);

        return ans;
    }
};