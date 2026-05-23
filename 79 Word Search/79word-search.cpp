class Solution {
public:
    vector<vector<bool>>visited;
    bool f(vector<vector<char>>& board, string ans, string word, int i, int j){
        
         if(i>=board.size() || i<0 || j>=board[0].size() || j<0){
              return false;
         }
         //below line is for optimisatin purpose only 
         if(ans.size()>0 && ans[ans.size()-1]!=word[ans.size()-1]){
            return false;
         }
         visited[i][j] = true;
          ans = ans+board[i][j];
         if(ans==word){
            return true;
         }
         bool l = false;
         int dx[4] = {-1,1,0,0};
         int dy[4] = {0,0,1,-1};
         for(int k =0; k<4; k++){
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx>=0 && nx<board.size() && ny>=0 && ny<board[0].size() && visited[nx][ny]==false){
               
                l = l||f(board,ans,word,nx,ny);
                if(l==true){
                    return true;
                }
               
                
            }
         }
        
          visited[i][j] = false;
         return l;
         
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        visited.resize(m,vector<bool>(n,false));
        string ans = "";
       // ans = ans+board[0][0];
        bool k = false;
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                k = k||f(board,ans,word,i,j);
                if(k==true){
                    return true;
                }
            }
        }
        return k;


        
    }
};