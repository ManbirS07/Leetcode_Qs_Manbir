# Broken Calculator

This document explains the concept and approach to solving the "Broken Calculator" problem on LeetCode.

## Problem Statement

You are given two integers `startValue` and `target`. In one operation, you can either:
- Multiply the current number by 2, or
- Subtract 1 from the current number.

Your goal is to find the minimum number of operations needed to transform `startValue` to `target`.

## Approach

1. **Reverse Operations**:
   - Instead of transforming `startValue` to `target`, we can reverse the operations and transform `target` to `startValue`.
   - If `target` is greater than `startValue`, we can:
     - If `target` is even, divide it by 2.
     - If `target` is odd, add 1 to it.
   - If `target` is less than or equal to `startValue`, the only option is to subtract 1 from `startValue` until it equals `target`.

2. **Count Operations**:
   - Initialize a counter to keep track of the number of operations.
   - Use a loop to repeatedly apply the reverse operations until `target` is less than or equal to `startValue`.
   - Add the difference between `startValue` and `target` to the counter to account for the remaining subtractions.

### Example Code

```cpp
#include <iostream>
using namespace std;

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int operations = 0;
        while (target > startValue) {
            if (target % 2 == 0) {
                target /= 2;
            } else {
                target += 1;
            }
            operations++;
        }
        return operations + (startValue - target);
    }
};

int main() {
    Solution solution;
    int startValue = 2;
    int target = 3;
    int result = solution.brokenCalc(startValue, target);

    cout << "Minimum operations: " << result << endl;

    return 0;
}