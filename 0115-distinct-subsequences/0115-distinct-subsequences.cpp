class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        unsigned dp[1001][1001] = {0};

        for(int i = 0; i <= n; i++) dp[i][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = (s[i-1] == t[j-1]) ? dp[i-1][j-1] + dp[i-1][j] : dp[i-1][j];
            }
        }  
        return dp[n][m];
    }
};
