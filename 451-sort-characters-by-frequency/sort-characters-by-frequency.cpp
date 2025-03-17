class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int>mpp;

        for(int i=0;i<n;i++)
        {
            mpp[s[i]]++;
        }

        vector<pair<char,int>>arr(mpp.begin(),mpp.end());

        sort(arr.begin(), arr.end(), [](pair<char,int>& a, pair<char,int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
});

        string str="";
       for(auto it :arr)
       {
        for(int i=0;i<it.second;i++)
        {
            str+=it.first;
        }
       }
        return str;
    }
};