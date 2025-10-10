class Solution {
public:

    int minTaps(int n, vector<int>& ranges) {
        vector<long long int>dp(n+1,INT_MAX);
        dp[0] =0;
        for(int i =0; i<=n; i++){
            long long int start  = max(0,i-ranges[i]);
            long long int end = min(n,i+ranges[i]);
            for(int j =start; j<=end; j++){
                dp[end] = min(dp[end],dp[j]+1);
            }
     
        }
        if(dp[n]==INT_MAX){
            return -1;
        }
        return dp[n];
    }
};