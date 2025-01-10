class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        vector<char>a=s;
        for(int i=0;i<n;i++)
        {
            s[i]=a[n-i-1];
        }

    }
};