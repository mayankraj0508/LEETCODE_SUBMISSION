class Solution {
public: 
    int dp[71][71][71];
    int  f(vector<vector<int>>&grid,int i,int j1,int j2){
        if(j1<0|| j1>=grid[0].size() || j2<0 || j2>=grid[0].size() ){
            return INT_MIN;
        }
        if(i==grid.size()-1){
            if(j1==j2){
                return dp[i][j1][j2]= grid[i][j1];
            }
            else{
                return dp[i][j1][j2]=  grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int ans = INT_MIN;
        int dx[3] = {-1,1,0};
        int dy[3] = {0,1,-1};
        for(int m=0; m<3; m++){
            for(int n=0; n<3; n++){

                if(j1==j2){
                    ans = max(ans,grid[i][j1]+f(grid,i+1,j1+dx[m],j2+dy[n]));
                }
                else{
               
                    ans = max(ans,grid[i][j1]+grid[i][j2]+f(grid,i+1,j1+dx[m],j2+dy[n]));
                }
            }
        }
        return dp[i][j1][j2]= ans;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return f(grid,0,0,grid[0].size()-1);

        
    }
};