class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        
        for(int t = 0; t <= amount; t++) {
            if(t % coins[0] == 0) {
                dp[0][t] = t/coins[0]; //converting base case of recursion
            } else dp[0][t] = 1e9;
        }

        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= amount; t++) {
                int take = INT_MAX;
                int notTake = 0 + dp[i-1][t];

                if(coins[i] <= t) {
                    take = 1 + dp[i][t-coins[i]];
                }
                dp[i][t] = min(take, notTake);
            }
        }
        return dp[n-1][amount] == 1e9 ? -1 : dp[n-1][amount];
    }
};