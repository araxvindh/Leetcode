class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size();
        int l2=nums2.size();
       long long  int maxScore=0;
        int mod=1e9+7;
        int i=0;
        int j=0;
        long long  int s1=0;
        long long int s2=0;

        while(i<l1 && j<l2)
        {
            if(nums1[i]==nums2[j])
            {
                maxScore+=max(s1,s2)+nums1[i];
                i++;
                j++;
                s1=0;
                s2=0;
            }
            else if(nums1[i] < nums2[j])
            {
                s1+=nums1[i];
                i++;
            }else
            {
                s2+=nums2[j];
                j++;
            }
        }
        while(i<l1)
        {
            s1+=nums1[i];
            i++;
        }

        while(j<l2)
        {
            s2+=nums2[j];
            j++;
        }
        maxScore+=max(s1,s2);
        maxScore=maxScore%mod;
        return (int)maxScore;
    }
};