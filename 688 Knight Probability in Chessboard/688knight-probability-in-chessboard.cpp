class Solution {
public:
   double dp[30][30][105];
    int p;
   double f(int i,int j,int k){
    if(i<0||j<0||i>=p||j>=p){
        return 0;
    }
    if(k==0){
        return 1;
    }
    if(dp[i][j][k]!=-1.0){
        return dp[i][j][k];
    }
     return dp[i][j][k] =  f(i+1, j+2, k-1)*1.0/8 +
            f(i+2, j+1, k-1)*1.0/8 +
            f(i-1, j+2, k-1)*1.0/8+
            f(i-2, j+1, k-1)*1.0/8 +
            f(i+1, j-2, k-1)*1.0/8 +
            f(i+2, j-1, k-1)*1.0/8 +
            f(i-1, j-2, k-1)*1.0/8 +
            f(i-2, j-1, k-1)*1.0/8;
   }
    double knightProbability(int n, int k, int row, int column) {
        p =n;
        for(int i = 0; i < 30; i++){
    for(int j = 0; j < 30; j++){
        for(int k = 0; k < 105; k++){
            dp[i][j][k] = -1.0;
    }
}
}

//memset(dp,-1.0,sizeof(dp));
        return f(row,column,k);
        
    }
};