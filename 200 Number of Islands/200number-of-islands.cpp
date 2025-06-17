class Solution {
public:
//unordered_set<pair<int,int>>visited;
void dfs(int row,int col,vector<vector<char>>&grid){
    if(row>=grid.size()||col>=grid[0].size()||grid[row][col]=='0'){
        return ;
    }
    grid[row][col]='0';
    if(row<grid.size()-1){
    dfs(row+1,col,grid);
    }
    if(col<grid[0].size()-1){
    dfs(row,col+1,grid);
    }
    dfs(row-1,col,grid);
    dfs(row,col-1,grid);
}

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i =0; i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]!='0'){
                    ans++;

                    dfs(i,j,grid);
                    grid[i][j] = '0';
                }
        }
        }
        
                
            
        
        return ans;

        
    }
};