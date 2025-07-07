# House Robber Problem - Dynamic Programming Solutions

This document explains the dynamic programming approaches for the classic House Robber problems.

## House Robber I

### Problem Statement

Given an integer array `nums` representing the amount of money at each house, return the maximum amount of money you can rob tonight without alerting the police (cannot rob adjacent houses).

### Approach

- Use a DP array where `dp[i]` represents the maximum money that can be robbed from the first `i` houses.
- At each house, decide to either:
  - **Take**: Rob the current house and add its value to `dp[i-2]`.
  - **Not Take**: Skip the current house and take `dp[i-1]`.
- The answer is `dp[n]`.

### Time Complexity

- **O(n)**

### Space Complexity

- **O(n)**

### Example Code

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i = 2; i <= n; i++) {
            int take = nums[i - 1] + dp[i - 2];
            int notTake = dp[i - 1];
            dp[i] = max(take, notTake);
        }
        return dp[n];
    }
};