class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<pair<int,int>>pq;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                pq.push({grid[i][j],i});  // pq.push(make_pair(grid[i][j],i))
             }
        }

        long  maxSum=0;
        int cnt=0;
        while(k!=0 && !pq.empty())
        {
            int val=pq.top().first;
            int index=pq.top().second;
            pq.pop();
            if(limits[index]>0)
            {
                maxSum+=val;
                limits[index]--;
                k--;
            }
        }
        return maxSum;
    }
};