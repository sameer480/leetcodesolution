#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:    
    int findLowestCoins(vector<int> &coins, int cur, int amount, vector<vector<int>> &dp) {
        if (cur == coins.size() || amount <= 0)
            return (amount == 0) ? 0 : INT_MAX - 1;   
        
        if (dp[cur][amount] != -1)
            return dp[cur][amount];
        
        int res = -1;
        if (coins[cur] > amount) {
            int doNotTakeCoin = 0 + findLowestCoins(coins, cur + 1, amount, dp);
            dp[cur][amount] = res = doNotTakeCoin;
        }
        else {
            int takeCoin = 1 + findLowestCoins(coins, cur, amount - coins[cur], dp);
            int doNotTakeCoin = 0 + findLowestCoins(coins, cur + 1, amount, dp);
            dp[cur][amount] = res = min(takeCoin, doNotTakeCoin);
        }
        return dp[cur][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1)); 
        int res = findLowestCoins(coins, 0, amount, dp);
        return (res >= INT_MAX - 1) ? -1 : res;
    }
};
