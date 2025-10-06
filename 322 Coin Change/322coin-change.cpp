class Solution {
public: 
    vector<int>dp;
    int f(vector<int>&coins,int x,int n){
        if(x==0){
            return dp[x]=0;
        }
      
        if(dp[x]!=-1){
            return dp[x];
        }
        int ans = INT_MAX-1;
        for(int i =0; i<coins.size(); i++){
            if(coins[i]<=x){
           dp[x] =  ans = min(ans,1+f(coins,x-coins[i],n));
            }

        }
        
        return dp[x] =ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int x =amount;
        if(amount==0){
            return 0;
        }
        dp.resize(10005,-1);
        int ans = f(coins,x,amount);
        if(ans>=INT_MAX-1){
         return -1;
         }
         return ans;
        
        

        
    }
};