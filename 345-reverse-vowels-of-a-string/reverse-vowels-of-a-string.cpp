class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> mpp = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<int>vowels;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(mpp.contains(s[i]))
            {
                vowels.push_back(s[i]);
            }
        }

        reverse(vowels.begin(),vowels.end());
        string ans="";
        int start=0;
        for(int i=0;i<n;i++)
        {
            if(mpp.contains(s[i]))
            {
                ans+=vowels[start];
                start++;
            }
            else
            {
                ans+=s[i];
            }
        }

        return ans;
    }
};