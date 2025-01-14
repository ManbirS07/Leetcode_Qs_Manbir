# Kth Largest Element in an Array

This document explains the concept and approach to finding the Kth largest element in an array.

## Problem Statement

Given an array of integers `nums` and an integer `k`, return the `k`th largest element in the array. Note that it is the `k`th largest element in sorted order, not the `k`th distinct element.

## Approach -> COUNTING SORT


### Using a Frequency Array

1. **Find Minimum and Maximum Elements**:
   - Determine the minimum (`minn`) and maximum (`maxx`) elements in the array.

2. **Create a Frequency Array**:
   - Create a frequency array `ans` of size `maxx - minn + 1` to store the frequency of each element in the range from `minn` to `maxx`.

3. **Populate the Frequency Array**:
   - Iterate through the input array `nums` and update the frequency array `ans` based on the occurrences of each element.

4. **Determine the Kth Largest Element**:
   - Iterate through the frequency array `ans` from the highest index to the lowest.
   - Decrement `k` by the frequency of the current element.
   - When `k` becomes less than or equal to 0, return the current element (adjusted by adding `minn`).

### Time Complexity

- **O(n)**: Finding the minimum and maximum elements, populating the frequency array, and determining the Kth largest element all take linear time.

### Space Complexity

- **O(maxx - minn + 1)**: The space required for the frequency array.

## Example Code

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int minn = *min_element(nums.begin(), nums.end());
        int maxx = *max_element(nums.begin(), nums.end());

        int size = maxx - minn + 1;
        // Frequency array
        vector<int> ans(size, 0);

        // Populate the frequency array
        for (int num : nums) {
            ans[num - minn]++;
        }

        // Determine the Kth largest element
        for (int i = size - 1; i >= 0; i--) {
            k -= ans[i];
            if (k <= 0) {
                return i + minn;
            }
        }
        return -1;
    }
};

Dry Run Example
Consider the following array and k value:
nums = [5, 3, 2, 5, 7, 4]
k = 2

Steps
Find minimum and maximum elements:

minn = 2
maxx = 7
Create a frequency array of size 7 - 2 + 1 = 6:

ans = [0, 0, 0, 0, 0, 0]
Populate the frequency array:

nums = [5, 3, 2, 5, 7, 4]
ans = [1, 0, 1, 1, 2, 1] (frequencies of elements from 2 to 7)
Determine the Kth largest element:

Iterate from the end of ans:
i = 5, k = 2 - 1 = 1
i = 4, k = 1 - 2 = -1 (k <= 0)
Return i + minn = 4 + 2 = 6
Result
The 2nd largest element in the array is 6.