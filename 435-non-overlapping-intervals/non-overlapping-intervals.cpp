class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());

        int cnt=0;

        int end=arr[0][1];

        for(int i=1;i<n;i++)
        {

            if(end>arr[i][0])
            {
                cnt++;
                end=min(end,arr[i][1]);
            }
            else
            {
                end=arr[i][1];
            }
        }
        return cnt;
    }
};