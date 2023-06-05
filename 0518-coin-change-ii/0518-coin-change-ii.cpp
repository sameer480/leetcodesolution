class Solution {
public:
    int solve(int amount, const vector<int>& coins, int index, vector<vector<int>>& memo) {
        // Check if the result for the current amount and index is already computed and stored in the memo table.
        if (memo[amount][index] != -1) {
            return memo[amount][index];
        }

        // Base case: If the amount is zero, a valid combination is found.
        if (amount == 0) {
            return 1;
        }

        // Base case: If the amount is negative or we have exhausted all coins, no valid combination can be formed.
        if (amount < 0 || index == coins.size()) {
            return 0;
        }

        int results = 0;
        for (int i = index; i < coins.size(); i++) {
            // Recursive call: Try using the current coin and explore remaining possibilities.
            if (amount >= coins[i]) {
                results += solve(amount - coins[i], coins, i, memo);
            }
        }

        // Store the computed result in the memo table for future use.
        memo[amount][index] = results;

        return results;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(amount + 1, vector<int>(coins.size(), -1));  // Memo table initialized with -1

        return solve(amount, coins, 0, memo);
    }
};
