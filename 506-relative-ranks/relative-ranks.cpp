class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        vector<int> ans = score;

        sort(ans.begin(), ans.end(), greater<int>());

        map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[ans[i]] = i;
        }

        vector<string> res;
        for (int i = 0; i < n; i++) {
            int rank = mpp[score[i]];
            if (rank == 0) {
                res.push_back("Gold Medal");
            } else if (rank == 1) {
                res.push_back("Silver Medal");
            } else if (rank == 2) {
                res.push_back("Bronze Medal");
            } else {
                res.push_back(to_string(rank + 1));
            }
        }

        return res;
    }
};
