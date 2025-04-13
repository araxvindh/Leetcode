class Solution {
public:
    int findClosest(int x, int y, int z) {
        
        int xDis=abs(z-x);
        int yDis=abs(z-y);

         if(xDis<yDis)
        {
            return 1;
        }
        else if(yDis<xDis)
        {
            return 2;
        }

        return 0;
    }
};