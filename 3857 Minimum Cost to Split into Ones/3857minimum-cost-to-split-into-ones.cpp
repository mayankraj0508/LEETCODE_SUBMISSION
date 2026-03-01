class Solution {
public:
  vector<int>dp;
    int f(int n){
        int ans = INT_MAX;
            if(n==1){
            return 0;
        }
             
        if(dp[n]!=-1){
            return ans = dp[n];
        }
   
        for(int i =1; i<n; i++){
           ans = min(ans,i*(n-i)+f(i)+f(n- i));
            
        }
        return dp[n]=ans;
        
    }
    int minCost(int n) {
            dp.resize(n+1,-1);
        int an = f(n);
    
        return an;
 
        
        
    }
};