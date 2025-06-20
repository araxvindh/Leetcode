class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();

        queue<int>bfs;
        vector<bool>vis(n);
        bfs.push(start);

        while(!bfs.empty())
        {
            int val=bfs.front();
            vis[val]=true;
            bfs.pop();
           int x=val+arr[val];
           int y=val-arr[val];

           if(x<n && x>=0)
           {
                if(arr[x]==0) return true;
                if(!vis[x])
                {
                    bfs.push(x);
                }
           }

           if(y<n &&  y>=0)
           {
            if(arr[y]==0) return true;
            if(!vis[y])
            {
                bfs.push(y);
            }
           }
        }

        for(int i=0;i<n;i++)
        {
            if(arr[i]==0 && vis[i])
            {
                return true;
            }
        }

        return false;
    }
};