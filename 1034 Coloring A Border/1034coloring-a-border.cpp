class Solution {
public:
 vector<vector<int>>visited;
    void dfs(vector<vector<int>>&grid,int i,int j,int actual_col,int newcol){
        if(i>=grid.size()||i<0||j>grid[0].size()||j<0){
            return ;
        }
        if(i==grid.size()-1||i==0||j==grid[0].size()-1||j==0){
            grid[i][j] = newcol;
        }
        visited[i][j] = 1;
        int  dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};
        for(int k = 0; k<4; k++){
            int nx = i+dx[k];
            int ny  = j+dy[k];
            if(nx<grid.size()&& nx>=0 && ny<grid[0].size() && ny>=0 && visited[nx][ny]==0){
                if(grid[nx][ny]!=actual_col){
                    grid[i][j] = newcol;
           
                }
                else{
                    
                    dfs(grid,nx,ny,actual_col,newcol);
                }

            }
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int actual_col = grid[row][col];
        int newcol = color;
        visited.resize(grid.size(),vector<int>(grid[0].size(),0));

        dfs(grid,row,col,actual_col,newcol);
        return grid;
        
    }
};