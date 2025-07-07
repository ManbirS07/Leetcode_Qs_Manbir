# Longest Increasing Subsequence (LIS) - Tabulation (Bottom-Up DP)

This document explains the tabulation (bottom-up dynamic programming) approach to solving the Longest Increasing Subsequence (LIS) problem.

## Problem Statement

Given an integer array `nums`, return the length of the longest strictly increasing subsequence.

## Approach

This solution uses tabulation (bottom-up DP):

1. **DP Array**:  
   - `dp[i]` stores the length of the longest increasing subsequence ending at index `i`.
   - Initialize all `dp[i]` to `1` since every element is an LIS of length 1 by itself.

2. **Filling the DP Table**:  
   - For each index `i`, check all previous indices `j` (`0 <= j < i`).
   - If `nums[j] < nums[i]`, update `dp[i] = max(dp[i], 1 + dp[j])`.
   - Track the maximum value in `dp` as the answer.

## Time Complexity

- **O(n^2)**: Two nested loops over the array.

## Space Complexity

- **O(n)**: For the DP array.

## Example Code

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // tabulation
        int n = nums.size();
        vector<int> dp(n, 1);

        int ans = 1;

        for(int i = 0; i < n; i++) {
            int curr = nums[i];

            for(int j = 0; j < i; j++) {
                if(nums[j] < curr) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    ans = max(ans, dp[i]);
                }
            }
        }

        return ans;
    }
};