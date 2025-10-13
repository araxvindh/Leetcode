class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        
        vector<string>ans;
        ans.push_back(words[0]);

        for(int i=1;i<words.size();i++)
        {
            string b=words[i];
            string a=ans.back();

            sort(b.begin(),b.end());
            sort(a.begin(),a.end());

            if(a!=b) ans.push_back(words[i]);
        }
        return ans;
    }
};