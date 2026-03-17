class Solution {
public:
    
    bool check(vector<vector<int>>& mat,int r ,int c,int n,int m)
    {
        bool flag= true;
        for(int i=0;i<n;i++)
        {
            if(mat[i][c]==1 && i!=r)
            {
                flag=false;
            }
        }

        for(int j=0;j<m;j++)
        {
            if(mat[r][j]==1 && j!=c)
            {
                flag=false;
            }
        }

        return flag;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1 && check(mat,i,j,n,m))
                {
                    cnt++;
                }
            }
        }


        return cnt;
    }
};