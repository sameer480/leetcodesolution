class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& memo) {
        int r = matrix.size();
        int c = matrix[0].size();

        if (i == r) {
            return 0;
        }
        if (j < 0 || j >= c) {
            return INT_MAX;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int op1 = rec(i + 1, j - 1, matrix, memo);
        int op2 = rec(i + 1, j, matrix, memo);
        int op3 = rec(i + 1, j + 1, matrix, memo);
        memo[i][j] = matrix[i][j] + min(op1, min(op2, op3));
        return memo[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> memo(r, vector<int>(c, -1));
        int ans = INT_MAX;
        for (int i = 0; i < c; i++) {
            ans = min(ans, rec(0, i, matrix, memo));
        }
        return ans;
    }
};