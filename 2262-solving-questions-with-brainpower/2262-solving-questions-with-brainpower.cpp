#include <bits/stdc++.h>

class Solution {
public:
    long long solve(vector<vector<int>>& questions, vector<long long>& dp, int i, int n) {
        if (i >= n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        long long ans = INT_MIN;

        long long inc = questions[i][0] + solve(questions, dp, i + questions[i][1] + 1, n);
        long long ninc = solve(questions, dp, i + 1, n);
        ans = max(inc, ninc);

        dp[i] = ans;
        return dp[i];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        if (n == 0) {
            return 0;
        }
        int m = questions[0].size();
        vector<long long> dp(n + 1, -1);
        return solve(questions, dp, 0, n);
    }
};
