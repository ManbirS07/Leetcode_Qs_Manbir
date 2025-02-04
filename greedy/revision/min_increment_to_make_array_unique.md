# Minimum Increment to Make Array Unique

This document explains the concept and approach to solving the problem of finding the minimum number of increments required to make all elements in an array unique.

## Problem Statement

Given an array of integers `nums`, you need to find the minimum number of increments required to make all elements in the array unique. An increment involves increasing an element by 1.

## Approach

1. **Frequency Array**:
   - Use a frequency array to count the occurrences of each element in the array. This helps in reducing the time complexity to O(n).

2. **Initialize Frequency Array**:
   - Calculate the maximum element in the array.
   - Initialize a frequency array of size `n + maxx` to store the frequencies of elements, where `n` is the size of the input array and `maxx` is the maximum element in the array.

3. **Count Frequencies**:
   - Iterate through the input array and update the frequency array with the count of each element.

4. **Calculate Increments**:
   - Iterate through the frequency array:
     - If the frequency of an element is greater than 1, calculate the number of increments needed to make the element unique.
     - Distribute the excess frequency to the next element in the frequency array.
     - Update the total number of increments required.

5. **Return Result**:
   - Return the total number of increments required.

### Example Code

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int maxx = *max_element(begin(nums), end(nums));

        vector<int> freq(n + maxx, 0); // size of array is n + maxx to store frequencies

        for (auto &num : nums) {
            freq[num]++;
        }

        int ans = 0;
        for (int i = 0; i < n + maxx; i++) {
            if (freq[i] > 1) {
                int empty = freq[i] - 1;
                ans += empty;
                // distribute the excess frequency to the next# Minimum Increment to Make Array Unique

This document explains the concept and approach to solving the problem of finding the minimum number of increments required to make all elements in an array unique.

## Problem Statement

Given an array of integers `nums`, you need to find the minimum number of increments required to make all elements in the array unique. An increment involves increasing an element by 1.

## Approach

1. **Frequency Array**:
   - Use a frequency array to count the occurrences of each element in the array. This helps in reducing the time complexity to O(n).

2. **Initialize Frequency Array**:
   - Calculate the maximum element in the array.
   - Initialize a frequency array of size `n + maxx` to store the frequencies of elements, where `n` is the size of the input array and `maxx` is the maximum element in the array.

3. **Count Frequencies**:
   - Iterate through the input array and update the frequency array with the count of each element.

4. **Calculate Increments**:
   - Iterate through the frequency array:
     - If the frequency of an element is greater than 1, calculate the number of increments needed to make the element unique.
     - Distribute the excess frequency to the next element in the frequency array.
     - Update the total number of increments required.

5. **Return Result**:
   - Return the total number of increments required.

### Example Code

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int maxx = *max_element(begin(nums), end(nums));

        vector<int> freq(n + maxx, 0); // size of array is n + maxx to store frequencies

        for (auto &num : nums) {
            freq[num]++;
        }

        int ans = 0;
        for (int i = 0; i < n + maxx; i++) {
            if (freq[i] > 1) {
                int empty = freq[i] - 1;
                ans += empty;
                 // distribute the excess occurrences to the next positions
                freq[i + 1] += empty;
            }
        }
        return ans;
    }
};