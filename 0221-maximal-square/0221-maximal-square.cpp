class Solution {
public:
    int dp[301][301];
    int solve(int i, int j, int n, int m, vector<vector<char>>& grid) {
        if(i >= n || j >= m || i < 0 || j < 0) return 0;

        if(grid[i][j] == '0') return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i, j + 1, n, m, grid);
        int down = solve(i + 1, j, n, m, grid);
        int diag = solve(i + 1, j + 1, n, m, grid);

        return dp[i][j] = 1 + min({right, down, diag});
    }
    int maximalSquare(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    ans = max(ans, solve(i, j, n, m, grid));
                }
            }
        }
        return ans * ans;
    }
};