class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        dp[0][0] = 1;

        // Initialize the first row
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 0) {
                dp[0][i] = dp[0][i - 1];
            }
        }

        // Initialize the first column
        for (int j = 1; j < m; j++) {
            if (obstacleGrid[j][0] == 0) {
                dp[j][0] = dp[j - 1][0];
            }
        }

        // Fill the remaining cells
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
