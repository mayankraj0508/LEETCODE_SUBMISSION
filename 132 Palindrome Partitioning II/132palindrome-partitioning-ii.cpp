class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<vector<int>> isPal;  // for palindrome check memo

    bool isPalindrome(string &s, int i, int j) {
        if (i >= j) return true;
        if (isPal[i][j] != -1) return isPal[i][j];
        return isPal[i][j] = (s[i] == s[j]) && isPalindrome(s, i + 1, j - 1);
    }

    int f(string &s, int i) {
        if (i == n) return 0; // no cuts needed beyond end
        if (dp[i][n-1] != -1) return dp[i][n-1];

        int ans = INT_MAX;
        for (int k = i; k < n; k++) {
            if (isPalindrome(s, i, k)) {
                if (k == n - 1) ans = 0; // last substring is palindrome
                else ans = min(ans, 1 + f(s, k + 1));
            }
        }
        return dp[i][n-1] = ans;
    }

    int minCut(string s) {
        n = s.size();
        dp.assign(n, vector<int>(n, -1));
        isPal.assign(n, vector<int>(n, -1));
        return f(s, 0);
    }
};