class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 1); //dp[i] -> length of current increasing subarray ending at i

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                dp[i] = dp[i - 1] + 1;
        }

        for (int i = 0; i + 2*k <= n; i++) {
            if (dp[i + k - 1] >= k && dp[i + 2*k - 1] >= k)
            //if inc[i + k - 1] == k it means that k length ki subarray yaha tak strictly increaing h 
                return true;
        }
        return false;
    }
};
