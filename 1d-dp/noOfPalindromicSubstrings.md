# Count Palindromic Substrings - Dynamic Programming Template

This document explains a classic dynamic programming template for counting all palindromic substrings in a given string.

## Problem Statement

Given a string `s`, return the number of palindromic substrings in it. A substring is palindromic if it reads the same backward as forward.

## Approach

This solution uses a 2D dynamic programming table to efficiently count all palindromic substrings.

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
   - Increment the count whenever a palindrome is found.

3. **Result**:
   - Return the total count of palindromic substrings.

### Time Complexity

- **O(n^2)**: Two nested loops over the string.

### Space Complexity

- **O(n^2)**: For the DP table.

## Example Code

```cpp
class Solution {
public:
    // dp[i][j] -> true if substring from i to j is a palindrome else false
    int dp[1001][1001];
    int countSubstrings(string s) {
        int n = s.length();

        memset(dp, 0, sizeof(dp));
        int cnt = 0;
        for(int len = 1; len <= n; len++) { // length of substring
            for(int i = 0; (i + len - 1) < n; i++) {
                int j = i + len - 1; // end index

                if(i == j) {
                    dp[i][j] = 1; // single character
                }
                else if(i + 1 == j) {
                    if(s[i] == s[j]) dp[i][j] = 1; // two characters
                } else {
                    if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                        dp[i][j] = 1; // longer substrings
                    }
                }

                if(dp[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};