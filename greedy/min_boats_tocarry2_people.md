# Minimum Boats to Carry 2 People

This document explains the concept and approach to solving the problem of finding the minimum number of boats required to carry people given a weight limit per boat.

## Problem Statement

You are given an array `people` where `people[i]` represents the weight of the `i`-th person, and an integer `limit` which represents the maximum weight a boat can carry. Each boat can carry at most two people at the same time, provided the sum of the weights of those people is at most `limit`.

Your task is to find the minimum number of boats required to carry every person.

## Approach

1. **Sort the Array**:
   - Sort the array `people` in ascending order to facilitate pairing the lightest and heaviest people together.

2. **Two-Pointer Technique**:
   - Use two pointers `i` and `j` to represent the lightest and heaviest person, respectively.
   - Initialize the number of boats `ans` to 0.
   - Traverse the array using the two pointers:
     - If the sum of the weights of the people at pointers `i` and `j` is less than or equal to `limit`, increment `i` and decrement `j`, and increment the boat count `ans`.
     - If the sum exceeds the limit, decrement `j` and increment the boat count `ans`.
     - If `i` equals `j`, it means only one person is left, so increment the boat count `ans` by 1 and return the result.

3. **Return Result**:
   - Return the total number of boats required.

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
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people), end(people));
        int n = people.size();
        int i = 0, j = n - 1;
        int ans = 0;
        while (i <= j) {
            if (i == j) return ans + 1;
            if (people[i] + people[j] <= limit) {
                i++;
                j--;
                ans++;
            } else {
                j--;
                ans++;
            }
        }
        return ans;
    }
};