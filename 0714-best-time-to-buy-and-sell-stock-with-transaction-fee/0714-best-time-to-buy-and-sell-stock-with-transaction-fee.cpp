class Solution {
public:
    int solve(int i, vector<int>& prices, int fee, int bag, vector<vector<int>>& dp) {
        if (i >= prices.size()) {
            return 0;
        }
        if (dp[i][bag] != -1) {
            return dp[i][bag];
        }
        if (bag == 1) {
            int op1 = prices[i] - fee + solve(i + 1, prices, fee, 0, dp);
            int op2 = solve(i + 1, prices, fee, 1, dp);
            return dp[i][bag] = max(op1, op2);
        } else {
            int op1 = -prices[i] + solve(i + 1, prices, fee, 1, dp);
            int op2 = solve(i + 1, prices, fee, 0, dp);
            return dp[i][bag] = max(op1, op2);
        }
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, prices, fee, 0, dp);
    }
};
