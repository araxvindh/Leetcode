class Solution {
public:
    int minOperations(string s) {
        

        int ans=0;

        for(auto ch : s)
        {
            int dis =(26 -(ch-'a') )%26;
            ans=max(ans,dis);
        }

        return ans;

    }
};