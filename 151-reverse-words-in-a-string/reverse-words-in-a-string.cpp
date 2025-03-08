class Solution {
public:
    string reverseWords(string s) {
        vector<string>ans;
        stringstream ss(s);
        string word;

        while(ss>>word)
        {
            ans.push_back(word);
        }

        string str;
        for(int i=ans.size()-1 ; i>=0;i--)
        {
            str+=ans[i];
            if(i!=0)
            {
                str+=" ";
            }
        }
        return str;
    }
};