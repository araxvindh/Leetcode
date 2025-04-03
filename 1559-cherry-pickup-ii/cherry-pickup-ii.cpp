class Solution {
public:

    int findCherry(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int n, int m, int i, int j1, int j2)
    {
        if (j1 >= m || j2 >= m || j1 < 0 || j2 < 0)
        {
            return -1e8; 
        }

        if (i == n - 1)
        {
            if (j1 == j2)
            {
                return grid[i][j1];
            }
            else
            {
                return grid[i][j1] + grid[i][j2];
            }
        }

        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = INT_MIN;

        for (int d1 = -1; d1 <= 1; d1++)
        {
            for (int d2 = -1; d2 <= 1; d2++)
            {
                int val = 0;
                if (j1 == j2)
                {
                    val = grid[i][j1];
                }
                else
                {
                    val = grid[i][j1] + grid[i][j2];
                }

                val += findCherry(grid, dp, n, m, i + 1, j1 + d1, j2 + d2);
                maxi = max(val, maxi);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return findCherry(grid, dp, n, m, 0, 0, m - 1);
    }
};
