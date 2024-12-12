class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        vector<vector<int>>mat(n+1,vector<int>(n+1,0));
        sort(satisfaction.begin(),satisfaction.end());
        int maxlen=0;
        for(int time=1;time<=n;time++)
        {
            for(int dish=time;dish<=n;dish++)
            {
                mat[dish][time]=mat[dish-1][time-1]+(time*satisfaction[dish-1]);
                maxlen=max(maxlen,mat[dish][time]);
            }
        }
        return maxlen;
    }
};