class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        
        int n=cost.size();
        vector<int>answer(n,0);
        int min_so_far=cost[0];
        
        for(int i=0;i<n;i++){
            min_so_far=min(min_so_far,cost[i]);
            answer[i]=min_so_far;
        }


        return answer;

    }
};