class Solution {
public:

    void palindrome(string s,vector<vector<string>>&res,vector<string>&temp,int index)
    {
        if(index==s.size())
        {
            res.push_back(temp);
        }

        for(int i=index;i<s.size();i++)
        {
            if(isPalindrome(s,index,i))
            {
                temp.push_back(s.substr(index,i-index+1));
                palindrome(s,res,temp,i+1);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
            {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>res;
        vector<string>temp;

        palindrome(s,res,temp,0);

        return res;

    }
};