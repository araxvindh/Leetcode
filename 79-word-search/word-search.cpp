class Solution {
public:

    bool backTracking(vector<vector<char>>&board,int row,int col,string& word,int ind)
    {
        if(ind==word.size()) return true;

        if(row<0 || col<0 || row>=board.size() || col>= board[0].size() ||  board[row][col]!=word[ind])
        {
            return false;
        }
        char temp=board[row][col];
        board[row][col]='*';
        int r[]={-1,1,0,0};
        int c[]={0,0,-1,1};

        bool found;
        for(int i=0;i<4;i++)
        {
            int R=row+r[i];
            int C=col+c[i];

            
           if(backTracking(board,R,C,word,ind+1))
           {
            return true;
           }

        }

        board[row][col]=temp;

       return false; 
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if( backTracking(board,i,j,word,0))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};