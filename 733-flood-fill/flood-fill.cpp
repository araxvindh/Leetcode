class Solution {
public:

    void dfs(vector<vector<int>>&image,int sr,int sc,int color,int ele,vector<vector<int>>&ans)
    {
        int n=image.size();
        int m=image[0].size();
        ans[sr][sc]=color;
        int row[]={-1,1,0,0};
        int col[]={0,0,-1,1};

        for(int i=0;i<4;i++)
        {
            int r=row[i]+sr;
            int c=col[i]+sc;

            if(r>=0 && c>=0 && r<n && c<m && image[r][c]==ele && ans[r][c]!=color)
            {
                dfs(image,r,c,color,ele,ans);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int ele= image[sr][sc];
        vector<vector<int>>ans=image;
        dfs(image,sr,sc,color,ele,ans);

        return ans;
    }
};