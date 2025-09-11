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

    string sortVowels(string s) {
        vector<char>arr;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(isVowel(s[i]))
            {
                arr.push_back(s[i]);
            }
        }

        sort(arr.begin(),arr.end());

        int ind=0;
        for(int i=0;i<n;i++)
        {
            if(isVowel(s[i]))
            {
                s[i]=arr[ind++];
            }
        }

        return s;


    }
};