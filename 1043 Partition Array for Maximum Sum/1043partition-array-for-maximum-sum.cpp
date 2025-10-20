class Solution {
public:
    vector<int> ans;
    int n;
    vector<int>dp;
    int  f(int idx, vector<int>& arr, int k) {
        if (idx >= n) return 0;
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int kns = INT_MIN;
        int len = 0;
        int best = INT_MIN;
        for (int l = idx; l <= min(n - 1, idx + k - 1); l++) {
            kns = max(kns, arr[l]);
            len++;
            int total = kns* len + f(idx + len, arr, k);
            best = max(best, total);
        }
        return dp[idx] = best;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size()+1,-1);
        n = arr.size();
       ans.assign(n, INT_MIN);
       int ans =  f(0, arr, k);
       return ans;
      //  return 0;
    }
};
