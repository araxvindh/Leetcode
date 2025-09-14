class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int maxi=INT_MAX;
        int n=tasks.size();
        for(int i=0;i<n;i++)
        {
            int s=tasks[i][0];
            int e=tasks[i][1];

            maxi=min(maxi,s+e);
        }


        return maxi;
    }
};