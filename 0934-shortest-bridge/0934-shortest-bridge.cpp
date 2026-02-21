class Solution {
public:
    typedef pair<pair<int, int>, int> p;

    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited, int delrow[], int delcol[], int n, int m, queue<p>& q) {
        visited[i][j] = 1;
        q.push({{i, j}, 0});

        for (int k = 0; k < 4; k++) {
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];

            if (isValid(nrow, ncol, n, m)) {
                if (visited[nrow][ncol]) continue;

                if(grid[nrow][ncol] == 1) {
                    dfs(nrow, ncol, grid, visited, delrow, delcol, n, m, q);
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        // there are only 2 islands
        // first fully traverse the 1st island, and mark all those 1s
        // then from those ones, if we reach a cell with 1 that isn't visited, that
        // many flips are reqd
        int n = grid.size();
        int m = grid[0].size();

        int delrow[4] = {1, 0, -1, 0};
        int delcol[4] = {0, 1, 0, -1};

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<p> q;
        for (int i = 0; i < n; i++) {
            bool firstIsland = false;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid, visited, delrow, delcol, n, m, q);
                    firstIsland = true;
                    break;
                } 
            }
            if(firstIsland) break;
        }

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int flips = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (isValid(nrow, ncol, n, m)) {
                    if (visited[nrow][ncol]) continue;

                    if (grid[nrow][ncol] == 1)
                        return flips;
                    else {
                        q.push({{nrow, ncol}, flips + 1});
                        visited[nrow][ncol] = 1;
                    }
                }
            }
        }
        return -1;
    }
};