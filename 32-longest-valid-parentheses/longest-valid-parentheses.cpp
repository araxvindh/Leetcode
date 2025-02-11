class Solution {
public:
    int longestValidParentheses(string s) {
        //optimal soln without using  space

        int left=0;
        int right=0;
        int maxLen=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                left++;
            }
            else
            {
                right++;
            }
            if(left==right)
            {
                maxLen=max(maxLen,left*2);
            }

            if(right>left)
            {
                left=0;
                right=0;
            }
        }

          left=0;
         right=0;

        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='(')
            {
                left++;
            }
            else
            {
                right++;
            }
            if(left==right)
            {
                maxLen=max(maxLen,left*2);
            }

            if(right<left)
            {
                left=0;
                right=0;
            }
        }
        return maxLen;
    }
};