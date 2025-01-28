# Bag of Tokens

This document explains the concept and approach to solving the "Bag of Tokens" problem.

## Problem Statement

You are given an integer array `tokens` where `tokens[i]` represents the value of the `i`-th token and an integer `power`.

Your goal is to maximize your score by playing the tokens in the following way:
- If you have at least `tokens[i]` power, you can play the `i`-th token face up to gain 1 score and lose `tokens[i]` power.
- If you have at least 1 score, you can play the `i`-th token face down to gain `tokens[i]` power and lose 1 score.

Return the maximum score you can achieve after playing any number of tokens.

## Approach

1. **Edge Case Handling**:
   - If there is only one token, check if the power is sufficient to play it face up. If yes, return 1, otherwise return 0.

2. **Sort Tokens**:
   - Sort the tokens in ascending order to facilitate the greedy approach.

3. **Two-Pointer Technique**:
   - Use two pointers `i` and `j` to represent the current token to be played face up and face down, respectively.
   - Initialize the score `ans` to 0.
   - Traverse the tokens using the two pointers:
     - If the current power is greater than or equal to `tokens[i]`, play the token face up, increase the score, and decrease the power.
     - If the current power is less than `tokens[i]` and the score is at least 1, play the token face down, decrease the score, and increase the power.
     - If neither condition is met, return the current score.

4. **Return Result**:
   - Return the maximum score achieved.

### Time Complexity

- **O(n log n)**: The time complexity is dominated by the sorting step.

### Space Complexity

- **O(1)**: The space complexity is constant as no additional space is used other than a few variables.

## Example Code

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans = 0;
        int n = tokens.size();

        if (n == 1) {
            if (power < tokens[0]) return ans;
            else return 1;
        }

        sort(begin(tokens), end(tokens));
        int i = 0, j = n - 1;
        while (i <= j) {
            if (power >= tokens[i]) {
                ans++;
                power -= tokens[i];
                i++;
            } else {
                if (ans >= 1 && i != j) { // i == j means last element check
                    power += tokens[j];
                    ans--;
                    j--;
                } else return ans;
            }
        }
        return ans;
    }
};