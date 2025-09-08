class Solution {
public:
    int maximalSquare(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(grid[i][0] == '1') {
                dp[i][0] = 1; //single 1 is a square
                ans = 1;
            }
        }

        for(int j = 0; j < m; j++) {
            if(grid[0][j] == '1') {
                dp[0][j] = 1;
                ans = 1;
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(grid[i][j] == '1') {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};