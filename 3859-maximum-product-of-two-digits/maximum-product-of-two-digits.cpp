class Solution {
public:
    int maxProduct(int n) {
        vector<int>arr;
        while(n>0)
        {
            arr.push_back(n%10);
            n=n/10;
        }

        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                maxi=max(maxi,arr[i]*arr[j]);
            }
        }


        return maxi;
    }
};