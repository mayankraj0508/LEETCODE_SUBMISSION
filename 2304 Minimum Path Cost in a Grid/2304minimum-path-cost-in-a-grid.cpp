class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&cost){
        int ans = INT_MAX;
         if(dp[i][j]!=-1){
            return dp[i][j];
         }
        int temcost = grid[i][j]; 
      for(int k =0; k<grid[i].size(); k++){
        if(i==grid.size()-1){
            dp[i][j]=ans = min(ans,temcost);
        }
        else{
       dp[i][j] = ans = min(ans,cost[grid[i][j]][k]+temcost+f(i+1,k,grid,cost));
        }
      }  
      return dp[i][j]=  ans; 
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        dp.resize(55,vector<int>(55,-1));
        int ans=INT_MAX;
        for(int j=0; j<grid[0].size(); j++){
            ans=min(ans,f(0,j,grid,moveCost));
        }
        return ans;
    }
};