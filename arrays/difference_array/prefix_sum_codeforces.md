
# Codeforces 1832-B: Maximum Sum

This document explains the concept and approach to solving the Codeforces problem 1832-B "Maximum Sum".

## Problem Statement

You are given an array of integers. Your task is to find the maximum possible sum of elements after removing exactly `k` elements from the array. You can remove elements from either the beginning or the end of the array.

## Note:
The first instinct is to implement a greedy solution which removes either two minimums or one maximum, according to which of the options removes elements with smaller sum. Unfortunately, this doesn't work even on the examples
## Approach

1. **Prefix Sum Calculation**:
   - Calculate the prefix sum of the array to efficiently compute the sum of any subarray.

2. **Sliding Window Technique**:
   - Use a sliding window to consider all possible subarrays of length `n - k` (where `n` is the length of the array).
   - The maximum sum of such subarrays will give the result after removing `k` elements.

3. **Iterate and Compare**:
   - Iterate through all possible positions of the sliding window and keep track of the maximum sum encountered.

### Time Complexity

- **O(n)**: The prefix sum calculation and the sliding window technique both run in linear time.

### Space Complexity

- **O(n)**: Additional space is used for storing the prefix sums.

## Example Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumAfterRemovingKElements(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefixSum(n + 1, 0);

    // Calculate prefix sums
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    int maxSum = 0;

    // Sliding window to find the maximum sum of subarray of length n - k
    for (int i = 0; i <= k; ++i) {
        int currentSum = prefixSum[n - (k - i)] - prefixSum[i];
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << maxSumAfterRemovingKElements(nums, k) << endl;
    }
    return 0;
}