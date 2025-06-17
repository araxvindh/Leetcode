class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int maxi=INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(colors[i]!=colors[j])
                {
                    maxi=max(maxi,j-i);
                }
            }
        }

        return maxi;
    }
};