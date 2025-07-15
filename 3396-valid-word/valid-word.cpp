class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;

        bool is_vowel=false;
        bool is_const=false;
        for(auto it :word)
        {
            if(isalpha(it))
            {
                it=tolower(it);
                if(it=='a' || it=='e'|| it=='i' || it=='o'|| it=='u')
                {
                    is_vowel=true;
                }
                else
                {
                    is_const=true;
                }
            }
            else if(!isdigit(it))
            {
                return false;
            }
        }
        return is_vowel && is_const;
    }
};