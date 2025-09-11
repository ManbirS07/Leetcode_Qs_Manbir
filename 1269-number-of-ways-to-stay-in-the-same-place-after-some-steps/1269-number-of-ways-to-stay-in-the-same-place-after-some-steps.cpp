class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int i, int steps, int n, vector<vector<int>>& dp) {
        if(steps == 0) return i == 0;

        if(dp[i][steps] != -1) return dp[i][steps];

        long long left = 0, right = 0, stay = 0;
        if(i > 0) {
            left = solve(i - 1, steps - 1, n, dp);
        }  

        if(i < n - 1) {
            right = solve(i + 1, steps - 1, n, dp);
        }

        stay = solve(i, steps - 1, n, dp);

        return dp[i][steps] = (left + right + stay) % mod;
    }
    int numWays(int steps, int len) {
        int maxPos = min(steps, len);
        vector<vector<int>> dp(maxPos + 1, vector<int>(steps + 1, -1));
        return solve(0, steps, len, dp);
    }
};