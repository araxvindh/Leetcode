class Solution {
public:

    void merge(vector<vector<int>>&intervals,int n, vector<vector<int>>&ans)
    {
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);

        for(int i=1;i<n;i++)
        {
            if(ans.back()[1]>=intervals[i][0])
            {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }

    }

    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        vector<vector<int>>ans;
        merge(meetings,n,ans);

        int total=0;
        for(auto it :ans)
        {
            int s=it[0];
            int e=it[1];

            total+=e-s+1;
        }
        
        return days-total;
        
    }
};