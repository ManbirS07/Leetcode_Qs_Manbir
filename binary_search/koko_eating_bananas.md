# Koko Eating Bananas

This document explains the concept and approach to solving the "Koko Eating Bananas" problem.

## Problem Statement

Koko loves to eat bananas. There are `n` piles of bananas, the `i`-th pile has `piles[i]` bananas. The guards have gone and will come back in `h` hours.

Koko can decide her bananas-per-hour eating speed of `k`. Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them instead and will not eat any more bananas during that hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer `k` such that she can eat all the bananas within `h` hours.

## Approach

1. **Binary Search**:
   - Use binary search to find the minimum eating speed `k`.
   - Initialize the left boundary of the search to 1 (minimum possible speed) and the right boundary to the maximum number of bananas in any pile (maximum possible speed).

2. **Check Feasibility**:
   - For each midpoint `k` in the binary search, check if Koko can eat all the bananas within `h` hours at speed `k`.
   - Calculate the total hours required to eat all bananas at speed `k` by iterating through each pile and summing up the hours needed for each pile.

3. **Adjust Search Range**:
   - If Koko can eat all the bananas within `h` hours at speed `k`, move the right boundary to `k`.
   - Otherwise, move the left boundary to `k + 1`.

### Time Complexity

- **O(n log m)**: The binary search runs in `O(log m)` time, where `m` is the maximum number of bananas in any pile. For each midpoint, we check the feasibility in `O(n)` time, where `n` is the number of piles.

### Space Complexity

- **O(1)**: We use only a constant amount of extra space.

## Example Code

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canEatAll(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool canEatAll(vector<int>& piles, int h, int k) {
        int hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k; // Equivalent to ceil(pile / k)
        }
        return hours <= h;
    }
};