class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n=order.size();
        int m=friends.size();
        vector<int>ans;
        for(auto it : order)
        {
            for(int i=0;i<m;i++)
            {
                if(it==friends[i])
                {
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};