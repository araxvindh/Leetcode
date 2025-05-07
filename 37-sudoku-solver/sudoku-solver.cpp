class Cell{
    public:
    int row;
    int col;

    Cell(int r,int c): row(r),col(c){}
};



class Solution {
public:
    Cell unFilled(vector<vector<char>>&board){
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.'){
                    return Cell(r,c);
                }
            }
        }return Cell(-1,-1);
    }    

bool isValid(vector<vector<char>>&board,vector<int>&rflag,vector<int>&cflag,vector<int>&smflag){
        Cell toFill = unFilled(board);
        if(toFill.row==-1 && toFill.col==-1){
            return true;
        }
        for(int dig=1;dig<=9;dig++){
            int submix=(toFill.row/3)*3 + toFill.col/3;
            if ((rflag[toFill.row] & (1 << dig)) == 0 &&
                (cflag[toFill.col] & (1 << dig)) == 0 &&
                (smflag[submix] & (1 << dig)) == 0){
                rflag[toFill.row]|=(1<<dig);
                cflag[toFill.col]|=(1<<dig);
                smflag[submix]|=(1<<dig);
                board[toFill.row][toFill.col]=(char)dig+'0';
                if(isValid(board,rflag,cflag,smflag)){
                    return true;
                }else{
                    board[toFill.row][toFill.col]='.';
                    rflag[toFill.row]^=(1<<dig);
                    cflag[toFill.col]^=(1<<dig);
                    smflag[submix]^=(1<<dig);
                }

            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int n= board.size();
        int m=board[0].size();
        vector<int>rflag(n,0);
        vector<int>cflag(m,0);
        vector<int>smflag(n,0);
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
              char ch=board[row][col];
              int dig=(int) ch-'0';
              int smix=(row/3)*3+(col/3);
                if(ch!='.'){
                    rflag[row]|=(1<<dig);
                    cflag[col]|=(1<<dig);
                    smflag[smix]|=(1<<dig);
                }
            }
        }
        isValid(board,rflag,cflag,smflag);
       
    } 
};
