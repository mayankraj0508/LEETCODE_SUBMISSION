class Solution {
public:
    vector<vector<vector<int>>> dp;
    
    int f(vector<int>& prices, int i, int k, int on) {
        if(i == prices.size()) return 0;
        if(dp[i][k][on] != -1) return dp[i][k][on];

        int a = f(prices, i + 1, k, on); // skip
        int b = INT_MIN, c = INT_MIN;

        if(on == 0 && k == 1) {
            b = f(prices, i + 1, k, 1) - prices[i]; // buy
        } else if(on == 1) {
            c = prices[i] + f(prices, i + 1, k - 1, 0); // sell
        }

        return dp[i][k][on] = max(a, max(b, c));

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n, vector<vector<int>>(2, vector<int>(2, -1)));
        return f(prices, 0, 1, 0);
    }
};
