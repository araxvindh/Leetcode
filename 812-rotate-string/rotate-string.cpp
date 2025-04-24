class Solution {
public:
    bool rotateString(string s, string goal) {

         int n=s.size();
         int m=goal.size();

         if(n!=m) return false;

        s=s+s;

        return (s.find(goal)!=string::npos);
    }
};