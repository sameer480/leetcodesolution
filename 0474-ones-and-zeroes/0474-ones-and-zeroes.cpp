#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countz(string& str) {
        int cnt = 0;
        for (auto x : str) {
            if (x == '0')
                cnt++;
        }
        return cnt;
    }

    int counto(string& str) {
        int cnt = 0;
        for (auto x : str) {
            if (x == '1')
                cnt++;
        }
        return cnt;
    }

    int solve(vector<string>& str, int m, int n, int i, vector<vector<vector<int>>>& memo) {
        if (i >= str.size()) {
            return 0;
        }

        if (memo[m][n][i] != -1) {
            return memo[m][n][i];
        }

        int cnt0 = countz(str[i]);
        int cnt1 = counto(str[i]);
        int pick = INT_MIN;
        if (m >= cnt0 && n >= cnt1)
            pick = 1 + solve(str, m - cnt0, n - cnt1, i + 1, memo);

        int npick = solve(str, m, n, i + 1, memo);

        memo[m][n][i] = max(pick, npick);
        return memo[m][n][i];
    }

    int findMaxForm(vector<string>& str, int m, int n) {
        int k = str.size();
        vector<vector<vector<int>>> memo(m + 1, vector<vector<int>>(n + 1, vector<int>(k, -1)));

        return solve(str, m, n, 0, memo);
    }
};
