class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        unordered_map<int,int> mpp;
        for (int i = 0; i < matrix.size(); i++) {
            int size = matrix[i].size();
            int mini = INT_MAX;
            int colIndex = -1;
            for (int j = 0; j < size; j++) {
                if (matrix[i][j] < mini) {
                    mini = matrix[i][j];
                    colIndex = j;
                }
            }
            mpp[mini] = colIndex;
        }

        vector<int> ans;
        int cols = matrix[0].size();
        int rows = matrix.size();

        for (auto it : mpp) {
            int element = it.first;
            int index = it.second;
            int maxi = INT_MIN;
            for (int row = 0; row < rows; row++) {
                maxi = max(matrix[row][index], maxi);
            }
            if (maxi == element) ans.push_back(element);
        }

        return ans;
    }
};