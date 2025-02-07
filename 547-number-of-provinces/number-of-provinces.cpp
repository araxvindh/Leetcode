class DisjointSet
{
public:
    vector<int> rank1,parent,size1;
    DisjointSet(int n)
    {
        rank1.resize(n+1,0);
        parent.resize(n+1);
        size1.resize(n+1,1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }

    }

    int findUPar(int node)
    {

        if(node==parent[node])
            return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if(ulp_u==ulp_v) return ;

        if(rank1[ulp_u]<rank1[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else if( rank1[ulp_v] <rank1[ulp_u])
        {
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank1[ulp_u]++;
        }
    }


     void unionBySize(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(size1[ulp_u]<size1[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size1[ulp_v]+=ulp_u;
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size1[ulp_u]+=ulp_v;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n=mat.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
                if(mat[i][j]==1)
                {
                    ds.unionBySize(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(ds.findUPar(i)==i)
            {
                cnt++;
            }
        }
        return cnt;
    }
};