class Solution {
public:
  vector<vector<int>>dp;
  static const int MOD = 1e9 + 7;
    long long pow(int i,int x){
        long long ans = 1;
        for(long long k = 0;k<x; k++){
            ans = ans*i;

        }
        return (ans)%MOD;
    }
    int f(int n,int x,int num){
        if(x==0){
            return (n)%MOD;
        }
        if(n==0){
            return 1;
        }
                int a = pow(num,x);
          if(a>n){
            return 0;
        }
        if(n<0){
            return 0;
        }
        if(dp[n][num]!=-1){
            return (dp[n][num])%MOD;
        }
      
        int include = f(n-a,x,num+1);
        int exclude = f(n,x,num+1);
        return dp[n][num] = (include + exclude)%MOD;
    }
    int numberOfWays(int n, int x) { 
        dp.resize(n+1,vector<int>(n+1,-1));
        return f(n,x,1);


    }
};