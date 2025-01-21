# Grid Game

This document explains the concept and approach to solving the Grid Game problem.

## Problem Statement

Given a 2xN grid, two robots start at the top-left corner and the bottom-left corner of the grid, respectively. The first robot moves to the right and then down, while the second robot moves to the right and then up. The goal is to minimize the maximum sum of the path taken by the second robot after the first robot has chosen its path.

## Approach

### Detailed Explanation

1. **Initialize Sums**:
   - Calculate the total sum of the first row (`row1remainsum`).
   - Initialize the sum of the second row (`secondrowremainsum`) to 0.
   - Initialize the minimum sum for the second robot's path (`minsumRobot2foreachpath`) to the maximum possible value.

2. **Traverse the Grid**:
   - For each column `robo1` from 0 to N-1:
     - Subtract the value at `grid[0][robo1]` from `row1remainsum` as the first robot moves to the right.
     - Calculate the maximum path sum for the second robot (`pathsumforrobo2`) as the maximum of `row1remainsum` and `secondrowremainsum`.
     - Update `minsumRobot2foreachpath` to the minimum of its current value and `pathsumforrobo2`.
     - Add the value at `grid[1][robo1]` to `secondrowremainsum` as the first robot moves to the right.

3. **Return the Result**:
   - Return `minsumRobot2foreachpath` as the result.

### Time Complexity

- **O(N)**: We traverse each column exactly once.

### Space Complexity

- **O(1)**: We use only constant extra space.

## Example Code

```cpp
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long row1remainsum = accumulate(begin(grid[0]), end(grid[0]), 0LL);
        long long secondrowremainsum = 0;
        long long minsumRobot2foreachpath = LONG_LONG_MAX;

        for (long long robo1 = 0; robo1 < grid[0].size(); robo1++) {
            row1remainsum -= grid[0][robo1];
            long long pathsumforrobo2 = max(row1remainsum, secondrowremainsum);
            minsumRobot2foreachpath = min(minsumRobot2foreachpath, pathsumforrobo2);
            secondrowremainsum += grid[1][robo1];
        }
        return minsumRobot2foreachpath;
    }
};


Dry Run Example
Consider the following grid:

grid = [
  [2, 5, 4],
  [1, 5, 1]
]

1.Initialize sums:

- `row1remainsum = 2 + 5 + 4 = 11`
- `secondrowremainsum = 0`
- `minsumRobot2foreachpath = LONG_LONG_MAX`

2.Traverse the grid:**
robo1 = 0:
- `row1remainsum -= grid[0][0] = 11 -2= 9`
- `pathsumforrobo2 = max(9, 0) = 9`
- `minsumRobot2foreachpath = min(LONG_LONG_MAX, 9) = 9`
- `secondrowremainsum += grid[1][0] = 0 + 1 = 1`

robo1 = 1:
- `row1remainsum -= grid[0][1] = 9 - 5 = 4`
- `pathsumforrobo2 = max(4, 1) = 4`
- `minsumRobot2foreachpath = min(9, 4) = 4`
- `secondrowremainsum += grid[1][1] = 1 + 5 = 6`
robo1 = 2:
- `row1remainsum -= grid[0][2] = 4 - 4 = 0`
- `pathsumforrobo2 = max(0, 6) = 6`
- `minsumRobot2foreachpath = min(4, 6) = 4`
- `secondrowremainsum += grid[1][2] = 6 + 1 = 7`

3.Return the result:

minsumRobot2foreachpath = 4
Result
The minimum maximum sum of the path taken by the second robot is 4.


