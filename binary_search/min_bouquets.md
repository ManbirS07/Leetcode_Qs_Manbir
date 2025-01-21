# Minimum Number of Days to Make m Bouquets

This document explains the concept and approach to solving the "Minimum Number of Days to Make m Bouquets" problem.

## Problem Statement

You are given an integer array `bloomDay`, an integer `m`, and an integer `k`.

You want to make `m` bouquets. To make a bouquet, you need to use `k` adjacent flowers from the garden.

The garden consists of `n` flowers, the `i`-th flower will bloom in the `bloomDay[i]` day.

Return the minimum number of days you need to wait to be able to make `m` bouquets from the garden. If it is impossible to make `m` bouquets, return `-1`.

## Approach

1. **Binary Search**:
   - Use binary search to find the minimum number of days required.
   - Initialize the left boundary of the search to the minimum bloom day and the right boundary to the maximum bloom day.

2. **Check Feasibility**:
   - For each midpoint `days` in the binary search, check if it is possible to make `m` bouquets in `days` days.
   - Iterate through the `bloomDay` array and count the number of bouquets that can be made by checking if `bloomDay[i] <= days`.

3. **Adjust Search Range**:
   - If it is possible to make `m` bouquets in `days` days, move the right boundary to `days`.
   - Otherwise, move the left boundary to `days + 1`.

### Time Complexity

- **O(n log d)**: The binary search runs in `O(log d)` time, where `d` is the range of days. For each midpoint, we check the feasibility in `O(n)` time, where `n` is the number of flowers.

### Space Complexity

- **O(1)**: We use only a constant amount of extra space.

## Example Code

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m * k > n) return -1;

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMakeBouquets(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int days) {
        int bouquets = 0, flowers = 0;
        for (int day : bloomDay) {
            if (day <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets >= m;
    }
};