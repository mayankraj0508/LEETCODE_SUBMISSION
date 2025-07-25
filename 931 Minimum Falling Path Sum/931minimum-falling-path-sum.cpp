class Solution {
public:
    int n;
    vector<vector<int>>dp;

    long long ans(int row, int col, vector<vector<int>>& matrix) {
        if (row == n || col < 0 || col >= n) {
            return LLONG_MAX;  
        }

        if (row == n - 1) {
            return matrix[row][col]; 
        }
        if(dp[row][col]!=INT_MAX){
            return dp[row][col];
        }

        long long diagr = LLONG_MAX;
        long long diagl = LLONG_MAX;
        long long bel = LLONG_MAX;

        long long down = ans(row + 1, col, matrix);
        if (down != LLONG_MAX)
            bel = down + matrix[row][col];

        long long rightDiag = ans(row + 1, col + 1, matrix);
        if (rightDiag != LLONG_MAX)
            diagr = rightDiag + matrix[row][col];

        long long leftDiag = ans(row + 1, col - 1, matrix);
        if (leftDiag != LLONG_MAX)
            diagl = leftDiag + matrix[row][col];

        return dp[row][col] = min({bel, diagl, diagr});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        dp.resize(n,vector<int>(n,INT_MAX));
        long long sum = LLONG_MAX;
        for (int j = 0; j < matrix[0].size(); j++) {
            sum = min(sum, ans(0, j, matrix));
        }
        return (int)sum;
    }
};
