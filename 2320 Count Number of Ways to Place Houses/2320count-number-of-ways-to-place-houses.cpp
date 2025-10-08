class Solution {
public:
vector<int>dp;
int mod =1e9+7;
 long long   int f(int i,int n){
    if(i>n){
        return 1;
    }
    if(i==n){
        return 2;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
      return  dp[i] =(f(i+1,n)+f(i+2,n))%mod;
   }
    int countHousePlacements(int n) {
        dp.resize(n+1,-1);
     long long int  ans = f(1,n);
       int MOD = 1e9+7;
       long long p = ans*ans;
       return p%MOD;
    }
};