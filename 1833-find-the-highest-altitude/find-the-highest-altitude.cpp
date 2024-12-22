class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int presum=0;
        int maxii=0;
        for(int i=0;i<n;i++)
        {
            presum+=gain[i];
            maxii=max(presum,maxii);
        }
        return maxii;
    }
};