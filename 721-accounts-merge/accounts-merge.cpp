class DisjointSet
{
    vector<int> rank1,parent,size1;

public:
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail=accounts[i][j];

                if(mpp.find(mail)==mpp.end())
                {
                    mpp[mail]=i;
                }
                else
                {
                    ds.unionBySize(i,mpp[mail]);
                }
            }
        }

        vector<vector<string>>mergedMail(n);
        
        for(auto it :mpp)
        {
            string mail=it.first;
            int node=ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>>ans;

        for(int i=0;i<n;i++)
        {
            if(mergedMail[i].size()==0) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it :mergedMail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};