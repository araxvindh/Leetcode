class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int>mR;
        vector<int>mC;

        for(int i=0;i<n;i++)
        {
            int mini=INT_MAX;
            for(int j=0;j<m;j++)
            {
                mini=min(mini,matrix[i][j]);
            }
            mR.push_back(mini);
        }


        
        for(int j=0;j<m;j++)
        {
            int maxi=INT_MIN;
            for(int i=0;i<n;i++)
            {
                maxi=max(maxi,matrix[i][j]);
            }
            mC.push_back(maxi);
        }

        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==mR[i] && matrix[i][j]==mC[j])
                {
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
        
    }


};