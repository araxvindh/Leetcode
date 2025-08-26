class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int diaSq = 0;   
        int area = 0;   
        
        for (auto& it : dimensions) {
            int len = it[0];
            int width = it[1];

            int curDiaSq = (len * len) + (width * width);
            int curArea = len * width;

           
            if (curDiaSq > diaSq || (curDiaSq == diaSq && curArea > area)) {
                diaSq = curDiaSq;
                area = curArea;
            }
        }

        return area;
    }
};
