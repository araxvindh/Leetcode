class dsu {
public:
    vector<int> parent, rank;
    
    dsu(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findPar(parent[node]); // Path compression
    }

    void unionByRank(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv) return;

        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size()/2;
        dsu ds(n);
        for(int i=0;i<row.size();i+=2)
        {
            ds.unionByRank(row[i]/2,row[i+1]/2);
        }

        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(ds.findPar(i)==i)
            {
                cnt++;
            }
        }
        return n-cnt;
    }
};