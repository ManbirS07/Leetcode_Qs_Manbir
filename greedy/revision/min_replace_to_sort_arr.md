# Minimum Replacement to Sort Array

This document explains the concept and approach to solving the problem of finding the minimum number of replacements required to sort an array in non-decreasing order.

## Problem Statement

Given an array of integers `nums`, you need to find the minimum number of replacements required to sort the array in non-decreasing order. A replacement involves splitting an element into multiple parts such that the sum of the parts equals the original element.

## Approach

1. **Start from the Back**:
   - Start iterating from the second last element to the first element. This is because if the current element is sorted, then the elements to its left will automatically be sorted.

2. **Check for Irregularities**:
   - If `nums[i] <= nums[i+1]`, continue to the next element.
   - If `nums[i] > nums[i+1]`, calculate the number of parts to split `nums[i]` into such that the left part is as large as possible but not larger than `nums[i+1]`.

3. **Calculate Parts and Operations**:
   - Calculate the number of parts as `nums[i] / nums[i+1]`.
   - If there is a remainder, increment the number of parts by 1.
   - The number of operations required is `parts - 1`.
   - Update `nums[i]` to `nums[i] / parts` to ensure the left part is as large as possible but not larger than `nums[i+1]`.

4. **Return Result**:
   - Return the total number of operations required.

### Example Code

```cpp
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long op = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) continue;
            else {
                int parts = nums[i] / nums[i + 1];
                if ((nums[i] % nums[i + 1]) != 0) parts++;
                op += parts - 1;
                nums[i] /= parts;
            }
        }
        return op;
    }
};