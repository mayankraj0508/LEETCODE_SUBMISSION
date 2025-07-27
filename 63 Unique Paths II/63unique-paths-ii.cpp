class Solution {
public:
   vector<vector<int>>dp;
   int ans(vector<vector<int>>&grid,int row,int col){
    if(row==grid.size()-1&&col==grid[0].size()-1){
        return 1;
    }
    if(row<0||col<0||row>=grid.size()||col>=grid[0].size()){
        return  0;
    }
    if(grid[row][col]==1){
        return 0;
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    return dp[row][col] = ans(grid,row,col+1) + ans(grid,row+1,col);
   }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        dp.resize(grid.size(),vector<int>(grid[0].size(),-1));
        if(grid[grid.size()-1][grid[0].size()-1]==1){
            return 0;
        }
        
        return ans(grid,0,0);

        
    }
};