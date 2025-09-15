class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int>mpp;
        for(auto it : brokenLetters){
            mpp[it]++;
        }
        stringstream ss(text);
        string word;
        int cnt=0;
        vector<string>words;

        while(ss>>word)
        {
            words.push_back(word);
        }

        for(auto it: words)
        {
            for(char c:it)
            {
                if(mpp.find(c)!=mpp.end())
                {
                    cnt++;
                    break;
                }
            }
        }

        return words.size()-cnt;
    }
};