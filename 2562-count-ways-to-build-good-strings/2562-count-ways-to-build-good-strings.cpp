class Solution {
public:
    int solve(int low, int high, int zero, int one, int i, vector<long long>& dp) {
        long long mod = 1e9 + 7;
        if (i > high) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
         dp[i] = i >= low ? 1 : 0;
        dp[i] += solve(low, high, zero, one, i + zero, dp);
        dp[i] += solve(low, high, zero, one, i + one, dp);
        dp[i] %= mod;
        return dp[i];
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high + 1, -1);
        return solve(low, high, zero, one, 0, dp);
    }
};
