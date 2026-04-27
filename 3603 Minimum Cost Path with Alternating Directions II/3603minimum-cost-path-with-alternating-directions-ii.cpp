class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {

        const long long INF = 1e18;

        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, INF)));

        // base case
        dp[m-1][n-1][0] = 0;
        dp[m-1][n-1][1] = 0;

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){

                if(i == m-1 && j == n-1) continue;

                // sec = 1 (move)
                long long right = (j+1 < n) ? (1LL+i)*(2LL+j) + dp[i][j+1][0] : INF;
                long long down  = (i+1 < m) ? (2LL+i)*(1LL+j) + dp[i+1][j][0] : INF;

                dp[i][j][1] = min(right, down);

                // sec = 0 (wait)
                dp[i][j][0] = waitCost[i][j] + dp[i][j][1];
            }
        }

        return 1 + dp[0][0][1];
    }
};