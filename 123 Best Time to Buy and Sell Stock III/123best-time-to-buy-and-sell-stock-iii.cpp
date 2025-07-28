class Solution {
public:
   int dp[100000][3][2];
   int f(vector<int>&prices,int i,int k,bool on){
    if(i>=prices.size()){
        return 0;
    }
     int p = (int)on;
       if(dp[i][k][p]!=-1){
        return dp[i][k][p];
       }
      int a =f(prices,i+1,k,on);
      int b = INT_MIN;
      int c = INT_MIN;
      if(on==false&&k>0){
        b = f(prices,i+1,k,true)-prices[i];

      }
      else if(on==true){
        c= prices[i] + f(prices,i+1,k-1,false);
      }
      return dp[i][k][p] = max(a,max(b,c));
   }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(prices,0,2,false);
        
    }
};