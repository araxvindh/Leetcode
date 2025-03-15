class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int >ans;
        int n=digits.size();
        int sum=1;
        int rem;
       
        for(int i=n-1;i>=0;i--){
            sum=sum+digits[i];
            rem=sum%10;
            ans.insert(ans.begin(), rem);
            sum=sum/10;
        }
        if(sum!=0){
            ans.insert(ans.begin(), sum);
        }
        return ans;
    }
};