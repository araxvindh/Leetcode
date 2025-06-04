class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string s;
        map<string,int>cnt1,cnt2;

        for(auto it :banned)
        {
            cnt1[it]++;
        }

        paragraph+=' ';

        for(auto it :paragraph)
        {
            if(it>='a' && it<='z' || it>='A' && it<='Z')
            {
                if(it>='a' && it<='z' )
                {
                    s+=it;
                }
                else
                {
                    s+=it+32;
                }
            }
            else
            {
                if(!s.empty()&& cnt1[s]==0)
                {
                    cnt2[s]++;
                }

                s.clear();
            }
        }

        int x=0;

        for(auto it :cnt2)
        {
            x=max(it.second,x);
        }

        for(auto it:cnt2)
        {
            if(it.second==x)
            {
                return it.first;
            }
        }

        return " ";
    }
};