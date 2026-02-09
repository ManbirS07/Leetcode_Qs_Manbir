class Solution {
public:
    int solve(int i, vector<int>& nums, int d) {
        int n = nums.size();
        // we can't do more partitions from here so return 0
        if (i >= n && d > 0)
            return 1e9; // no idle days should be left

        if (i >= n)
            return 0;

        if (d == 0) {
            // complete all jobs today only
            return *max_element(begin(nums) + i, end(nums));
        }

        int maxx = nums[i];
        int ans = 1e9; // minimum total difficulty from index i using d+1 days
        for (int j = i; n - (j + 1) >= d;
             j++) { // so that remaining jobs are atleast equal to the remaining
                    // days
            maxx = max(maxx, nums[j]);
            if (d > 0) {
                int sum = maxx + solve(j + 1, nums, d - 1);
                ans = min(ans, sum);
            }
        }
        return ans;
    }
    int minDifficulty(vector<int>& nums, int d) {
        int n = nums.size();
        // Each remaining day must get at least one job
        if (n < d)
            return -1;

        int partitions = d - 1;
        vector<vector<int>> dp(n + 1, vector<int>(d, 1e9));

        // base cases
        dp[n][0] = 0;
        int maxDiff = nums[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            maxDiff = max(nums[i], maxDiff);
            dp[i][0] = maxDiff;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int t = 1; t <= partitions; t++) {
                int maxx = nums[i];
                for (int j = i; n - (j + 1) >= t; j++) {
                    maxx = max(maxx, nums[j]);
                    if (t > 0) {
                        int sum = maxx + dp[j + 1][t - 1];
                        dp[i][t] = min(dp[i][t], sum);
                    }
                }
            }
        }

        return dp[0][partitions];
    }
};