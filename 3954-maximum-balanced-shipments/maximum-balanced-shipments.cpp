class Solution {
public:
    int maxBalancedShipments(vector<int>& w) {
        stack<int>st;
        int n=w.size();
        vector<int>pge(n);

        for(int i=0;i<n;i++)
        {
            while(!st.empty()&& w[st.top()]<=w[i])
            {
                st.pop();
            }

            if(st.empty()) pge[i]=-1;
            else  pge[i]=st.top();
            st.push(i); 
        }

        int cnt=0;
        int index=-1;

        for(int i=0;i<n;i++)
        {
            if(pge[i]!=-1)
            {
                if(pge[i]>index)
                {
                    cnt++;
                    index=i;
                }
            }
        }

        return cnt;
    }
};