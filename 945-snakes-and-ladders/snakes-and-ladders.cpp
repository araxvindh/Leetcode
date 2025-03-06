class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int>cells(n*n+1);
        int row=n-1;
        int col=0;
        int diff=1;
        for(int i=1;i<=n*n;i++)
        {
            cells[i]=board[row][col];
            col=col+diff;

            if(col==-1||col==n)
            {
                col=diff==1 ?n-1:0;
                diff=-diff;
                row--;
            }
        }

        vector<int>moves(n*n+1,-1);
        moves[1]=0;
        queue<int>q;
        q.push(1);
        while(!q.empty())
        {
            int sq=q.front();
            q.pop();

            for(int i=sq+1;i<=min(sq+6,n*n);i++)
            {
                int dest = (cells[i]==-1)?i:cells[i];
                if(moves[dest]== -1)
                {
                    moves[dest]=moves[sq]+1;
                    q.push(dest);
                }

            }
        }
        return moves[n*n];

    }
};