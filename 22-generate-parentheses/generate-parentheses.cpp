class Solution {
public:
    
     void find(int n,vector<string>&ans,int op ,int cp,  string a)
    {
        if(op==n && cp==n)
        {
            ans.push_back(a);
            return;
        }
        if(op<n)
        {
            find(n,ans,op+1,cp,a+'(');
        }
        if(cp<op)
        {
            find(n,ans,op,cp+1,a+')');
        }
        
    }


    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string a="";
         find(n,ans,0,0,a);
         return ans;
    }
};