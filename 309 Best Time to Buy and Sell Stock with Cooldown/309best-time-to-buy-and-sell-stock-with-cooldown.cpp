class Solution {
public:
    int dp[5005][2][10];
    int f(vector<int>&prices,int i,bool on,int p){
        if(i>=prices.size()){
            return 0;
        }
        int q = (int)on;
        if(dp[i][q][p]!=-1){
            return dp[i][q][p];
        }
        int a = f(prices,i+1,on,1);
        int b = INT_MIN;
        int c = INT_MIN;
        if(on==false&&i>=0&&p!=5){
            b = f(prices,i+1,true,1)-prices[i];

        }
      else if(on==true){
        c = prices[i] + f(prices,i+1,false,5);
      }
      return dp[i][q][p]=max(a,max(b,c));

    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(prices,0,false,1);

        
    }
};