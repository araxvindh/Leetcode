class Solution {
public:

    bool isVowel(char s)
    {
        if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u')
        {
            return true;
        }
        return false;
    }


    int maxFreqSum(string s) {
        map<int,int>vMap;
        map<int,int>cMap;

        for(char it :s)
        {
            if(isVowel(it))
            {
                vMap[it]++;
            }
            else
            {
                cMap[it]++;
            }
        }

        int vMax=0;
        int cMax=0;

        for(auto it :vMap)
        {
            vMax=max(vMax,it.second);
        }

        for(auto it :cMap)
        {
            cMax=max(cMax,it.second);
        }

        return vMax+cMax;
    }
};