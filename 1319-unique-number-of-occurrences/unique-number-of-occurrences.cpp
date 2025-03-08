class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mpp;
        set<int>s;
        for(int i=0;i<arr.size();i++)
        {
            mpp[arr[i]]++;
        }

        for(auto it :mpp)
        {
            s.insert(it.second);
        }

        return mpp.size()==s.size();
    }
};