class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int wcnt=0;
        int bcnt=0;
        int i=0;
        int j=0;
        int mini=INT_MAX;
        while(j<n)
        {
            if(blocks[j]=='W')
            {
                wcnt++;
                j++;
            }
            else if(blocks[j]=='B')
            {
                bcnt++;
                j++;
            }

            if(bcnt+wcnt==k)
            {
                 mini=min(mini,wcnt);
                if(blocks[i]=='W')
                {
                    wcnt--;
                }else
                {
                    bcnt--;
                }
                i++;
               
            }
        }
        return mini;

    }
};