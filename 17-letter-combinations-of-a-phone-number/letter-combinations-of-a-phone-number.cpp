class Solution {
public:
    unordered_map<char,string> mpp={
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };


    vector<string> letterCombinations(string digits) {
        vector<string>result;
        if(digits.empty()) return result;
        string comb;
        solve(digits,0,comb,result);
        return result;
    }

    void solve(const string& digits,int index ,string& comb,vector<string>&result )
    {
        if(index==digits.size()){
            result.push_back(comb);
            return ;
        }

        string letters =mpp[digits[index]];
        for (char letter : letters) {
            comb.push_back(letter);
            solve(digits, index + 1, comb, result);
            comb.pop_back();
        }
    }
};