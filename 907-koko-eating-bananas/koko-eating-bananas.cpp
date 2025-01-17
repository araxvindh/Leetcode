class Solution {
public:
int findMax(vector<int> &v){
    int n=v.size();
    int maxi= INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,v[i]);
    }return maxi;
}
long long funTo(vector<int>&v,int hourly){
    int n=v.size();
    long long hour=0;
    for(int i=0;i<n;i++){
        hour+=ceil((double)v[i]/(double) hourly);
    }return hour;
}

    int minEatingSpeed(vector<int>& v, int h) {
    int low=1;
   int high= findMax(v);
   while(low<=high){
       int mid=(low+high)/2;
       long long totalHours= funTo(v,mid);
       if(totalHours <= h){
           high=mid-1;
       }else{
           low=mid+1;
       }
   }return low;
}
};