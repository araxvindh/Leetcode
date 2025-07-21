class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        string a="";

        for(int i=0;i<n;i++)
        {
            int len=a.size();
            if(len>=2 && s[i]==s[i-1] && s[i]==s[i-2])
            {
                continue;
            }

            a+=s[i];
        }

        return a;
    }
};