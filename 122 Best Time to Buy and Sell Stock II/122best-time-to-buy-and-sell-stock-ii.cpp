class Solution {
public:
    int dp[100000][2];
    int f(vector<int>&prices,int i,bool on){
      
        int b = INT_MIN;
        int c = INT_MIN;
        int p = (int)on;
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][p]!=-1){
            return dp[i][p];
        }
          int a = f(prices,i+1,on);

        if(on==false){
             b = f(prices,i+1,true)-prices[i];

        }
        if(on==true){
            c = prices[i]+f(prices,i+1,false);
        }
        return dp[i][p] =max(a,max(b,c));

    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(prices,0,false);
        
    }
};