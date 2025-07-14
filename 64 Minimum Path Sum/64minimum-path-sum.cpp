class Solution {
public:
    vector<vector<int>>dp;
    int path(vector<vector<int>>&grid,int i,int j){
        int m = grid.size();
        int n = grid[0].size();
        if(i>=grid.size()||j>=grid[0].size()){
            return 1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==m-1&&j==n-1){
            return grid[i][j];
        }
        
        return dp[i][j] = min(grid[i][j]+path(grid,i,j+1),grid[i][j]+path(grid,i+1,j));
    }

    int minPathSum(vector<vector<int>>& grid) {
        dp.resize(grid.size(),vector<int>(grid[0].size(),-1));
       return path(grid,0,0);
        
    }
};