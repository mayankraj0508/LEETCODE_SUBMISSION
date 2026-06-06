class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
               int n = nums.size();
        
    
        vector<int> tokens;
        for (int i = 0; i < n; i++)
            if (s[i] == '1') tokens.push_back(i);
        
        int m = tokens.size();
        if (m == 0) return 0;
        

        
        const long long NEG_INF = LLONG_MIN / 2;
        
        vector<long long> dp(2);
        
        dp[0] = nums[tokens[0]];
        dp[1] = (tokens[0] > 0) ? nums[tokens[0] - 1] : NEG_INF;
        
        for (int i = 1; i < m; i++) {
            int pos = tokens[i];
            vector<long long> ndp(2, NEG_INF);

            ndp[0] = max(dp[0], dp[1]);
            if (ndp[0] != NEG_INF) ndp[0] += nums[pos];
            
    
            if (pos > 0) {
                int cover = pos - 1;

                
                long long best = NEG_INF;
                
                if (tokens[i-1] != cover && dp[0] != NEG_INF)
                    best = max(best, dp[0]);
                
             
                if (dp[1] != NEG_INF)
                    best = max(best, dp[1]);
                
                if (best != NEG_INF)
                    ndp[1] = best + nums[cover];
            }
            
            dp = ndp;
        }
        
        return max(dp[0], dp[1]);
        
    }
};