class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>lps(n);
        lps[0]=0;
        int len=0;
        for(int i=1;i<n;)
        {
            if(s[i]==s[len])
            {
               
                len++; 
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                {
                    len=lps[len-1];
                }
                else
                {  
                    lps[i]=0;
                    i++;
                  
                }
            }
        }
        return s.substr(0,lps[n-1]);
    }
};