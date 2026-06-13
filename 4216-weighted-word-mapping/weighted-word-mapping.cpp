class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(int i=0;i<words.size();i++)
        {
            int sum=0;
            for(auto ch : words[i])
            {
                int val= weights[ch-'a'];
                sum+=val;
            }
            sum=sum%26;
            ans+= 'z'-sum;
        }

        return ans;
    }
};