


class Solution {class DisjointSet
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

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DisjointSet ds(n);

        int extraEdges=0;
        for(auto  it :connections)
        {
            int u =it[0];
            int v=it[1];
            if(ds.findUPar(u)==ds.findUPar(v))
            {
                extraEdges++;
            }
            else
            {
                ds.unionBySize(u,v);
            }
        }

        int cntC=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i) cntC++;
        }

        int ans=cntC-1;

        if(extraEdges>=ans) return ans;
        return -1; 

    }
};