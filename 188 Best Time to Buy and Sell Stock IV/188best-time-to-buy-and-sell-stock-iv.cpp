class Solution {
public:
  int chartoint(char ch){
    if(ch==true){
        return 1;

    }
    else{
        return 0;
    }
    return 0;
  }
   int dp[1005][105][2];

    int f(vector<int>&prices, int i,int k, bool on ){
        if(i>=prices.size()){
            return 0;

        }
        int p = chartoint(on);
        if(dp[i][k][p]!=-1){
            return dp[i][k][p];
        }
        int a = f(prices,i+1,k,on);
        int b = INT_MIN;
        int c = INT_MIN;
        if(on==true){
            b = prices[i] + f(prices,i+1,k-1,false);

        }
        else if(k>0&&on==false){
            c = f(prices,i+1,k,true)-prices[i];
        }
        return dp[i][k][p]=max({a,b,c});
        

    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(prices,0,k,false);

        
        
    }
};