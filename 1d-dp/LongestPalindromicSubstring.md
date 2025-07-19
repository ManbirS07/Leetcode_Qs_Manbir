# Longest Palindromic Substring - Dynamic Programming Template

This document explains how to use a dynamic programming template to find the longest palindromic substring in a given string.

## Problem Statement

Given a string `s`, return the longest palindromic substring in `s`.

## Approach

This solution uses a 2D dynamic programming table to efficiently find the longest palindromic substring.

### DP Table Definition

- `dp[i][j]` is `true` (or `1`) if the substring from index `i` to `j` in `s` is a palindrome, otherwise `false` (or `0`).

### Steps

1. **Initialization**:
   - All substrings of length 1 are palindromes, so set `dp[i][i] = 1` for all `i`.

2. **Filling the DP Table**:
   - Iterate over all possible substring lengths from 1 to `n`.
   - For each length, iterate over all possible starting indices `i`.
   - Calculate the ending index `j = i + len - 1`.
   - For each substring `s[i..j]`:
     - If `i == j`, it's a single character (always a palindrome).
     - If `i + 1 == j`, it's a two-character substring. It's a palindrome if both characters are equal.
     - For longer substrings, `s[i..j]` is a palindrome if `s[i] == s[j]` and `dp[i+1][j-1]` is `1` (the inner substring is also a palindrome).
   - Whenever a palindrome is found, check if its length is greater than the current maximum. If so, update the starting index and maximum length.

3. **Result**:
   - Return the substring starting at `start` with length `maxlen`.

### Time Complexity

- **O(n^2)**: Two nested loops over the string.

### Space Complexity

- **O(n^2)**: For the DP table.

## Example Code

```cpp
class Solution {
public:
    int dp[1001][1001]; // dp[i][j] -> if the substr from i to j is a palindrome or not
    string longestPalindrome(string s) {
        // using template
        int n = s.size();
        memset(dp, 0, sizeof(dp));
        int maxlen = INT_MIN, start = -1;

        // taking substrings of all lengths
        for(int len = 1; len <= n; len++) {
            for(int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if(i == j) {
                    dp[i][j] = 1;
                } else if(i + 1 == j) {
                    if(s[i] == s[j]) {
                        dp[i][j] = 1;
                    }
                } else {
                    if(s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                        dp[i][j] = 1;
                    }
                }

                if(dp[i][j]) {
                    if(len > maxlen) start = i;
                    maxlen = max(maxlen, len);
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
                        
// How This Template Works

// The template checks all possible substrings in increasing order of length.

// It uses previously computed results (dp[i+1][j-1]) to efficiently check longer substrings.

// Whenever a palindrome is found, it updates the maximum length and starting index if needed.

// This approach ensures the longest palindromic substring is found in optimal time.
