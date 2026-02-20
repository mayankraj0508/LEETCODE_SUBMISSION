class Solution {
public:
    vector<vector<int>> dp;
    bool f2(string s, string t, int i, int j) {
        if (i == 0 && j == 0) {
            return true;
        }
        if (j == 0 && i > 0) {
            return false;
        }
        if (i == 0 && j > 0) {
            for (int k = 1; k <= j; k++) {
                if (t[k - 1] != '*') {
                    dp[i][j] = 0;
                    return false;
                }
            }
            dp[i][j] = 1;
            return true;
        }
        if (dp[i][j] != -1) {
            return dp[i][j] == 1;
        }
        if (s[i - 1] == t[j - 1] || t[j - 1] == '?') {
            return dp[i][j] = f2(s, t, i - 1, j - 1);
        } else {
            if (t[j - 1] == '*') {
                return dp[i][j] = f2(s, t, i, j - 1) || f2(s, t, i - 1, j);
            } else {
                dp[i][j] = 0;
                return false;
            }
        }
    }

    bool isMatch(string s, string p) {
        int i = 0;
        int j = 0;
        // memoizatio takes the extra auxillary space so to avoid it use 1 based
        // indexing and use taulation approach
        dp.resize(s.size() + 1, vector<int>(p.size() + 1, 0));
        dp[0][0] = 1;
        int flag = true;
        for (int j = 1; j <= p.size(); j++) {
            flag = true;
            for (int k = 1; k <= j; k++) {
                if (p[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        for (int i = 1; i < s.size() + 1; i++) {
            for (int j = 1; j <= p.size(); j++) {
               
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    if (p[j - 1] == '*') {
                         dp[i][j] =
                                  dp[i][j-1] || dp[i-1][j];
                    } else {
                        dp[i][j] = 0;
                       
                    }
                }
            }
        }
        int n = p.size();
        int m = s.size();
        return dp[m][n];
    }
};