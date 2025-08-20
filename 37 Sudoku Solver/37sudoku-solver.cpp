class Solution {
public:
   bool check(char ch,int row,int col,vector<vector<char>>& board){
    int a = row/3;
    int b = col/3;
    int sr,sc;
    sr = a*3;
    sc = b*3;
    for(int i = sr; i<sr+3; i++){
        for(int j =sc; j<sc+3;j++){
            if(board[i][j]==ch){
                return false;
            }
        }
    }
    for(int i =0; i<9; i++){
        if(board[i][col]==ch){
            return false;
        }
    }
    for(int j = 0; j<9; j++){
        if(board[row][j]==ch){
            return false;
        }

    }

return true;
    
   }
   bool solve(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j =0;j<9; j++){
                if(board[i][j]=='.'){
                    for(char ch= '1'; ch<='9';ch++){
                        if(check(ch,i,j,board)){
                            board[i][j] = ch;
                           if(solve(board)==true) return true;
                            board[i][j] = '.';
                        }

                    }
                    return false;
                }
            }
        }
        return true;
   }
    void solveSudoku(vector<vector<char>>& board) {
    
    solve(board);

        
    }
};