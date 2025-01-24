# Prefix Sum + Hashmap Approach

This document explains the Prefix Sum + Hashmap approach, which is useful for solving problems related to subarrays, such as:

- Counting the subarrays with some condition
- Finding the maximum length subarray with some condition
- Checking if a subarray exists with some given condition

This approach is particularly effective for problems dealing with subarray sums.

## Principle

The approach works on the following principle:

- If the prefix sum up to the `i`-th index is `X`, and the prefix sum up to the `j`-th index is `Y`, and it is found that `Y = X + k`, then the required subarray is found with `i` as the start index and `j` as the end index.

To store the index value and the sum of elements up to that index, a hashmap can be used.

## Why Use Prefix Sum + Hashmap?

The brute force method for subarray-related problems takes `O(n^2)` time to process each subarray plus extra time for processing. However, with the Prefix Sum + Hashmap approach, only `O(n)` time is required.

### Sliding Window Limitation

The sliding window approach is only applicable when we know for sure if the prefix sum is an increasing or decreasing function (i.e., monotonous in nature). For problems where negative input is given, the Prefix Sum + Hashmap approach is the best way to solve such problems.

## Applications

### 1. Count Subarrays with a Given Condition

**Data Structures Needed:**

- Integer variable for cumulative sum
- Unordered map

Example Code
Count Subarrays with a Given Sum
#include <unordered_map>
#include <vector>
using namespace std;

int countSubarraysWithSum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;
    int cumulativeSum = 0;
    int count = 0;

    for (int num : nums) {
        cumulativeSum += num;
        if (mp.find(cumulativeSum - k) != mp.end()) {
            count += mp[cumulativeSum - k];
        }
        mp[cumulativeSum]++;
    }

    return count;
}