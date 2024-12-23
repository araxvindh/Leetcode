class Solution {
public:
    bool isVowel(char s)
    {
        s=tolower(s);
        if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u')
        {
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<k;i++)
        {
            if(isVowel(s[i]))
            {
                cnt++;
            }
        }
        int maxii=cnt;
        for(int i=1;i<=n-k;i++)
        {
            if(isVowel(s[i-1]))
            {
                cnt--;
            }

            if(isVowel(s[i+k-1]))
            {
                cnt++;   
            }
            maxii=max(maxii,cnt);
        }
        return maxii;
    }
};