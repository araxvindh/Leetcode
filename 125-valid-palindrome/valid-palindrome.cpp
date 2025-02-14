class Solution {
public:
    bool isPalindrome(string s) {
        string s1,s2;
        for(auto it :s)
        {
            if(it>='a' && it<='z' || it>='0' && it<='9')
            {
                s1+=it;
            }

            if(it>='A' && it<='Z')
            {
                s1+=it+32;
            }
        }

        s2=s1;

        int left=0;
        int right=s1.size()-1;
        while(left<right)
        {
            swap(s1[left],s1[right]);
            left++;
            right--;
        }

        return s1==s2;
        
    }
};