# Prefix Common Array

This document explains the concept and approach to finding the prefix common array for two given arrays.

## Problem Statement

Given two arrays `a` and `b` of the same length `n`, the task is to find the prefix common array. The prefix common array is an array where each element at index `i` represents the count of common elements in the prefixes of `a` and `b` up to index `i`.

## Approach

1. **Initialize Frequency Array**:
   - Create a frequency array `freq` of size `n + 1` to store the frequency of each element in the arrays `a` and `b`.

2. **Initialize Result Array**:
   - Create an empty result array `ans` to store the prefix common counts.
   - Initialize a counter `cnt` to keep track of the number of common elements.

3. **Traverse the Arrays**:
   - For each index `i` from 0 to `n-1`:
     - Increment the frequency of `a[i]` and `b[i]` in the `freq` array.
     - If `a[i]` is equal to `b[i]` and its frequency becomes 2, increment the counter `cnt`.
     - Otherwise, if the frequency of `a[i]` or `b[i]` becomes 2, increment the counter `cnt`.
     - Append the current value of `cnt` to the result array `ans`.

4. **Return the Result**:
   - Return the result array `ans`.

### Time Complexity

- **O(n)**: We traverse the arrays once and update the frequency array and result array in constant time.

### Space Complexity

- **O(n)**: The space required for the frequency array and result array.

## Example Code

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> freq(n + 1, 0);
        vector<int> ans;
        int cnt = 0;

        for (int i = 0; i < a.size(); i++) {
            freq[a[i]]++;
            freq[b[i]]++;
            if (a[i] == b[i] && freq[a[i]] == 2) cnt++;
            else {
                if (freq[a[i]] == 2) cnt++;
                if (freq[b[i]] == 2) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


Dry Run Example
Consider the following arrays:

a = [1, 2, 3, 4]
b = [2, 1, 4, 3]

Steps
Initialize frequency array freq and result array ans:

freq = [0, 0, 0, 0, 0]
ans = []
cnt = 0
Traverse the arrays:

i = 0:
a[0] = 1, b[0] = 2
freq = [0, 1, 1, 0, 0]
cnt = 0
ans = [0]


i = 1:
a[1] = 2, b[1] = 1
freq = [0, 2, 2, 0, 0]
cnt = 2
ans = [0, 2]


i = 2:
a[2] = 3, b[2] = 4
freq = [0, 2, 2, 1, 1]
cnt = 2
ans = [0, 2, 2]


i = 3:
a[3] = 4, b[3] = 3
freq = [0, 2, 2, 2, 2]
cnt = 4
ans = [0, 2, 2, 4]
Result
The prefix common array is [0, 2, 2, 4]