# Longest Increasing Subsequence (LIS) - Recursive + Memoization

This document explains the recursive + memoization approach to solving the Longest Increasing Subsequence (LIS) problem.

## Problem Statement

Given an integer array `nums`, return the length of the longest strictly increasing subsequence.

## Approach

This solution uses recursion with memoization (top-down dynamic programming):

1. **Recursive Function**:  
   - The function `solve(nums, index, prev, dp)` explores two choices at each index:
     - **Take**: If the current number is greater than the previous number in the subsequence, include it and move to the next index.
     - **Skip**: Skip the current number and move to the next index.
   - The function returns the maximum length obtained by either taking or skipping the current number.

2. **Memoization**:  
   - A 2D DP array `dp[index][prev]` is used to store results for subproblems to avoid redundant calculations.
   - The `prev` parameter is `-1` when there is no previous element.

3. **Initialization**:  
   - The DP array is initialized with `-1` to indicate uncomputed states.
   - The recursion starts from index `0` with `prev = -1`.

## Time Complexity

- **O(n^2)**: Each state is defined by `index` and `prev`, both can take up to `n` values.

## Space Complexity

- **O(n^2)**: For the DP table.

## Example Code

```cpp
class Solution {
public:
    int n;
    int solve(vector<int>& nums, int index, int prev, vector<vector<int>>& dp) {
        if(index >= n) return 0;

        if(prev != -1 && dp[index][prev] != -1) {
            return dp[index][prev];
        }

        int take = 0;
        if(prev == -1 || nums[index] > nums[prev]) {
            take = 1 + solve(nums, index + 1, index, dp); // this index becomes the new previous
        }

        int skip = solve(nums, index + 1, prev, dp); // prev remains the same
        if(prev != -1) {
            dp[index][prev] = max(take, skip);
        }

        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(2501, vector<int>(2501, -1)); // 2-d since we have 2 changing states: index and previous
            return solve(nums, 0, -1, dp);
    }
};