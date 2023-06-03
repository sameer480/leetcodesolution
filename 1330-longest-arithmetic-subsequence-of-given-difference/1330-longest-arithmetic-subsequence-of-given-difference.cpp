class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        if (n <= 1) {
            return n;
        }
        
        int ans = 1;
        unordered_map<int, int> dp; // Using a single unordered_map for dynamic programming
        
        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            int prev = curr - difference;
            
            if (dp.find(prev) != dp.end()) {
                int count = dp[prev] + 1;
                dp[curr] = count;
                ans = max(ans, count);
            } else {
                dp[curr] = 1;
            }
        }
        
        return ans;
    }
};
