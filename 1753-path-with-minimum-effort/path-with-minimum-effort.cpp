class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>>mat(n,vector<int>(m,1e9));
        mat[0][0]=0;
        // {diff,{row,col}}
        pq.push({0,{0,0}});
        int row[]={-1,1,0,0};
        int col[]={0,0,-1,1};
        while(!pq.empty())
        {
            auto it =pq.top();
            pq.pop();

            int diff=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(r==n-1 && c==m-1) return diff;
            for(int i=0;i<4;i++)
            {
                int newR=r+row[i];
                int newC=c+col[i];

                if(newR>=0 && newR<n && newC>=0 && newC<m )
                {
                    int newEffort=max(abs(heights[newR][newC]-heights[r][c]),diff);

                    if(newEffort<mat[newR][newC])
                    {
                        mat[newR][newC]=newEffort;
                        pq.push({newEffort,{newR,newC}});
                    }
                }
            }
        }
        return 0;

    }
};