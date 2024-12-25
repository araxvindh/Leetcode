class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start=0;
        vector<vector<bool>> mat(n, vector<bool>(n, false));
        int maxLen = 1;
        for (int i = 0; i < n; i++) {

            mat[i][i] = true;
        }

        for (int i = 0; i <n - 1; i++) {
            if (s[i] == s[i + 1]) {
                mat[i][i + 1] = true;
                maxLen=2;
                start=i;
            }
        }

        for (int len = 3; len <= n; len++) {
            for (int ind = 0; ind <=n - len; ind++) {
                if (s[ind] == s[ind + len - 1] &&
                    mat[ind + 1][ind + len - 2]) {
                    mat[ind][ind + len - 1] = true;
                    if (len > maxLen) {
                    maxLen = len;
                    start = ind;
                }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};