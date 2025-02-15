# Rotten Oranges

## Problem Statement

You are given an `m x n` grid where each cell can have one of three values:
- `0` representing an empty cell,
- `1` representing a fresh orange, or
- `2` representing a rotten orange.

Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return `-1`.

## Example

**Input:**
grid = [ [2,1,1], [1,1,0], [0,1,1] ]


**Output:** `4`

## Approach

1. **Breadth-First Search (BFS)**:
   - Use BFS to simulate the process of rotting oranges minute by minute.
   - Use a queue to keep track of the positions of the rotten oranges.
   - For each rotten orange, rot the adjacent fresh oranges and add them to the queue.
   - Keep track of the time elapsed.

2. **Edge Cases**:
   - If there are no fresh oranges, return `0`.
   - If there are fresh oranges that cannot be reached by any rotten orange, return `-1`.

## Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;
        int minutes = 0;

        // Initialize the queue with all rotten oranges and count fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        // Directions for 4-directional movement
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // BFS to rot adjacent fresh oranges
        while (!q.empty() && freshOranges > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : directions) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        freshOranges--;
                    }
                }
            }
            minutes++;
        }

        return freshOranges == 0 ? minutes : -1;
    }
};

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    Solution sol;
    int result = sol.orangesRotting(grid);
    cout << "Minimum minutes to rot all oranges: " << result << endl; // Output: 4

    return 0;
}