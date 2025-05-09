class Solution {
public:
    bool judgeCircle(string moves) {
        
        int n=moves.size();

        map<char,int>mpp;

        for(auto it:moves)
        {
            mpp[it]++;
        }

        return mpp['U'] == mpp['D'] && mpp['L'] == mpp['R'];
    }
};