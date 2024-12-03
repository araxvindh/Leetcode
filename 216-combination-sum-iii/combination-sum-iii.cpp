class Solution {
public:
    void comb(vector<vector<int>>&ans,int n ,int k, int ind,vector<int>&temp)
    {
        if(n==0)
        {
            if(k==0)
            {
                ans.push_back(temp);
                return;
            }
            
        }
        for(int i=ind;i<=9;i++)
        {
            temp.push_back(i);
            comb(ans,n-1,k-i,i+1,temp);
            temp.pop_back();
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        comb(ans,k,n,1,temp);
        return ans;
    }
};