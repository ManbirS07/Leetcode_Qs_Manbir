# Count Servers that Communicate

This document explains the concept and approach to solving the problem of counting servers that communicate.

## Problem Statement

You are given a `m x n` grid where each cell represents a server. The value `grid[i][j]` is `1` if there is a server at cell `(i, j)`, and `0` otherwise.

Two servers communicate if they are in the same row or the same column. Your task is to count the number of servers that can communicate with at least one other server.

## Approach

1. **Count Servers in Rows and Columns**:
   - Use two arrays to count the number of servers in each row and each column.
   - Traverse the grid and update the counts for rows and columns.

2. **Count Isolated Servers**:
   - Traverse the grid again to count the number of isolated servers (servers that do not communicate with any other server).
   - A server is isolated if there is only one server in its row and only one server in its column.

3. **Calculate Result**:
   - Subtract the number of isolated servers from the total number of servers to get the number of servers that can communicate.

### Time Complexity

- **O(m * n)**: The grid is traversed twice, resulting in linear time complexity.

### Space Complexity

- **O(m + n)**: Additional space is used for the row and column count arrays.

## Example Code

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int total = 0;
        vector<int> roww(row);
        vector<int> coll(col);

        // Counting servers in each row and column
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    total++;
                    roww[i]++;
                    coll[j]++;
                }
            }
        }

        // Counting isolated servers
        int isol = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    if (roww[i] <= 1 && coll[j] <= 1) isol++;
                }
            }
        }

        return total - isol;
    }
};