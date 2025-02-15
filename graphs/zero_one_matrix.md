# 0/1 Matrix

## Problem Statement

Given an `m x n` binary matrix `mat`, return the distance of the nearest `0` for each cell.

The distance between two adjacent cells is `1`.

## Example

**Input:**
mat = [ [0,0,0], [0,1,0], [1,1,1] ]


## Approach

1. **Breadth-First Search (BFS)**:
   - Use BFS to find the shortest distance from each cell to the nearest `0`.
   - Initialize a queue with all the cells containing `0` and set their distance to `0`.
   - For each cell containing `1`, set its initial distance to infinity.
   - Process each cell in the queue, updating the distance of its neighbors if a shorter path is found.

2. **Edge Cases**:
   - If the matrix is empty, return an empty matrix.

## Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Initialize the queue with all the cells containing 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Directions for 4-directional movement
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // BFS to find the shortest distance to the nearest 0
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return dist;
    }
};

int main() {
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };
    Solution sol;
    vector<vector<int>> result = sol.updateMatrix(mat);
    cout << "Updated matrix with distances to nearest 0:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}