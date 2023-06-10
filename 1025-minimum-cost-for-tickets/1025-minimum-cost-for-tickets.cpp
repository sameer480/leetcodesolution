class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int i, vector<int>& dp, int n) {
        if (i >= n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int op1 = costs[0] + solve(days, costs, i + 1, dp, n);

        int j = i;
        int op2 = costs[1];
        while (j < n && days[j] < days[i] + 7) {
            j++;
        }
        op2 += solve(days, costs, j, dp, n);

        j = i;
        int op3 = costs[2];
        while (j < n && days[j] < days[i] + 30) {
            j++;
        }
        op3 += solve(days, costs, j, dp, n);

        dp[i] = min(op1, min(op2, op3));
        return dp[i];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, -1);
        return solve(days, costs, 0, dp, n);
    }
};
