class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int left=0;
        int right=0;
        string res;
        while(left<n && right <m)
        {
            res+=word1[left];
            res+=word2[right];
            left++;
            right++;
        }

        while(left<n)
        {
            res+=word1[left];
            left++;
        }
        while(right<m)
        {
            res+=word2[right];
            right++;
        }
        return res;
    }
};