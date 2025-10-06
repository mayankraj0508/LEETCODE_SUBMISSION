class Solution {
public:
    vector<vector<int>>dp;
    vector<int>digits;
    int MOD = 1e9+7;
    long long  f(int n,int k,int x){
        if(n==0&&x==0){
            return 1;
        }
       
            long long  ans = 0;
            if(dp[n][x]!=-1){
                return dp[n][x];
            }
            for(int j=0; j<k;  j++){
                if(n>0&&x>=digits[j]){
                ans =ans+f(n-1,k,x-digits[j]);
                }
            }
        
        return dp[n][x] = ans%MOD;
    }
    int numRollsToTarget(int n, int k, int target) {
        digits.resize(k);
        for(int i =0; i<k; i++){
            digits[i] = i+1;
        }
        dp.resize(31,vector<int>(1005,-1));
        return f(n,k,target);

        
    }
};