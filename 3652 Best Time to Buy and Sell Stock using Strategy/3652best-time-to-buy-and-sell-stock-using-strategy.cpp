class Solution {
public:
    vector<long long> prefBase, prefPrice;
    
    long long f(int idx, int k) {
        int mid = idx + k/2;
        int end = idx + k;

        // remove base contribution of [idx … end-1]
        long long removed = prefBase[end] - prefBase[idx];

        // add prices of second half [mid … end-1]
        long long added = prefPrice[end] - prefPrice[mid];

        return prefBase.back() - removed + added;
    }

    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        prefBase.assign(n+1, 0);
        prefPrice.assign(n+1, 0);

        for(int i = 0; i < n; i++) {
            prefBase[i+1] = prefBase[i] + 1LL * prices[i] * strategy[i];
            prefPrice[i+1] = prefPrice[i] + prices[i];
        }

        long long ans = prefBase.back();
        for(int i = 0; i <= n-k; i++) {
            ans = max(ans, f(i, k));
        }
        return ans;
    }
};

