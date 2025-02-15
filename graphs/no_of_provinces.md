## Approach

1. **Graph Representation**:
   - Represent the cities and their connections as a graph using an adjacency matrix.

2. **Depth-First Search (DFS)**:
   - Use DFS to traverse the graph and count the number of connected components (provinces).

## Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        visited[i] = true;
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                dfs(isConnected, visited, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                count++;
            }
        }
        return count;
    }
};

int main() {
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    Solution sol;
    int result = sol.findCircleNum(isConnected);
    cout << "Number of provinces: " << result << endl; // Output: 2

    return 0;
}