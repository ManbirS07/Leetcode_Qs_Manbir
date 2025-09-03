class Solution {
public:
    int dp[1001][1001];
    
    int solve(int i, int j, int n, int m, vector<int>& nums1, vector<int>& nums2) {
        if (i >= n || j >= m) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (nums1[i] == nums2[j]) {
            dp[i][j] = 1 + solve(i + 1, j + 1, n, m, nums1, nums2);
        } else {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        memset(dp, -1, sizeof(dp));
        int ans = 0;

        //checking max across all starting points
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, solve(i, j, n, m, nums1, nums2));
            }
        }
        return ans;
    }
};
