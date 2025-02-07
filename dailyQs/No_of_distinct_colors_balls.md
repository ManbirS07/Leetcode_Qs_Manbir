# LeetCode 3160: Number of Distinct Colors in a Ball

This document explains the concept and approach to solving the LeetCode problem 3160 "Number of Distinct Colors in a Ball".

## Problem Statement

You are given an array `colors` where `colors[i]` represents the color of the `i`-th ball. Your task is to find the number of distinct colors in the array.

## Approach

1. **Use a Set**:
   - Utilize a set data structure to store the unique colors from the `colors` array.
   - Iterate through the `colors` array and insert each color into the set.
   - The size of the set will give the number of distinct colors.

### Example Code

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countDistinctColors(vector<int>& colors) {
        unordered_set<int> uniqueColors;
        for (int color : colors) {
            uniqueColors.insert(color);
        }
        return uniqueColors.size();
    }
};

int main() {
    Solution solution;
    vector<int> colors = {1, 2, 2, 3, 4, 4, 5};
    int result = solution.countDistinctColors(colors);

    cout << "Number of distinct colors: " << result << endl;

    return 0;
}