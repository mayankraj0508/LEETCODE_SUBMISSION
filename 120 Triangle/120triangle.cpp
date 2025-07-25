class Solution {
public:
    vector<vector<int>> dp;
    
    int ans(int i, int j, vector<vector<int>>& triangle) {
        if (i == triangle.size()) return 0;

        if (dp[i][j] != INT_MIN) return dp[i][j];

        int one = triangle[i][j] + ans(i + 1, j, triangle);
        int two = triangle[i][j] + ans(i + 1, j + 1, triangle);

        return dp[i][j] = min(one, two);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp.assign(n, vector<int>(n, INT_MIN));  
        return ans(0, 0, triangle);
    }
};
