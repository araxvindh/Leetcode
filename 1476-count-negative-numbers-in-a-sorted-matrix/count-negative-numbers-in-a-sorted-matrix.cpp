class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int left=0;
            int right=m-1;

            while(left<=right)
            {
                int mid=(left+right)/2;

                if(grid[i][mid]<0)
                {
                    right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
            }
            cnt+=m-left;
        }

        return cnt;
    }
};