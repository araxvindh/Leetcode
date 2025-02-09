class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
private:
    bool valid(int row,int col,int n)
    {
        return row>=0 && col>=0  && row<n && col<n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0) continue;

                int row[]={-1,1,0,0};
                int col[]={0,0,-1,1};

                for(int k=0;k<4;k++)
                {
                    int newR=i+row[k];
                    int newC=j+col[k];

                    if(valid(newR,newC,n) && grid[newR][newC]==1)
                    {
                        int node=i*n+j;
                        int adjnode=newR*n+newC;
                        ds.unionBySize(node,adjnode);
                    }
                }
            }
        }
        //step 2 make any 0 to 1
        int mx=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col]==1) continue;

                int r[]={-1,1,0,0};
                int c[]={0,0,-1,1};
                set<int>val;
                for(int i=0;i<4;i++)
                {
                    int newR=row+r[i];
                    int newC=col+c[i];

                    if(valid(newR,newC,n))
                    {
                        if(grid[newR][newC]==1)
                        {
                            int adjnode=newR*n+newC;
                            val.insert(ds.findUPar(adjnode));
                           
                        }
                    }
                }
                int totalSize=0;
                for(auto it :val)
                {
                    totalSize+=ds.size[it];
                }
                mx=max(mx,totalSize+1);
                
            }
        }
        for(int cell=0;cell<n*n;cell++)
        {
            mx=max(mx,ds.size[ds.findUPar(cell)]);
        }

        return mx;
    }
};