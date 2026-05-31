class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        vector<int> bonus(n, 0);

        for (int i = 0; i < n; i++) {

            int fi = items[i][0];

            for (int j = 0; j < n; j++) {

                if (i == j) continue;

                int fj = items[j][0];

                if (fj % fi == 0) {
                    bonus[i]++;
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {

            int price = items[i][1];
            for (int b = budget; b >= price; b--) {

                dp[b] = max(
                    dp[b],
                    dp[b - price] + 1 + bonus[i]
                );
            }

            for (int b = price; b <= budget; b++) {

                dp[b] = max(
                    dp[b],
                    dp[b - price] + 1
                );
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};