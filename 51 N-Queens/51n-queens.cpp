class Solution {
public:
    vector<vector<string>>ans;
    bool check(int row, int col,vector<string>&chess){
        int n = chess.size();
        for(int i =0; i<=row-1; i++){
            for(int j = 0; j<n; j++){
                if(chess[i][j]=='Q' && abs(i-row)==abs(j-col)){
                    return false;
                }
                if(chess[i][j]=='Q' && j==col){
                    return false;
                }
            }
        }
        return true;
    }
    void f(int i,vector<string>&chess){
        if(i==chess.size()){

            ans.push_back(chess);
            return ;
        }
        int n = chess.size();
        for(int j=0; j<n; j++){
            if(check(i,j,chess)){
                chess[i][j] = 'Q';
                f(i+1,chess);
                chess[i][j] = '.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
         vector<string>chess(n,string(n,'.'));
          f(0,chess);
          return ans;

        
    }
};