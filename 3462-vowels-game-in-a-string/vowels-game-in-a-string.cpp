class Solution {
public:

    bool isVowel(char s)
    {
        s=tolower(s);

        if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u')
        {
            return true;
        }

        return false;

    }

    bool doesAliceWin(string s) {
        bool  flag= false;
        int  n=s.size();
        for(int i=0;i<n;i++)
        {
           if(isVowel(s[i]))
           {
            return true;
           }
        }
        return false;
    }
};