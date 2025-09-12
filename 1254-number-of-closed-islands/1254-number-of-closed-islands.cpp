class Solution {
public:
    int ans = 0;
    bool checkBoundary(int n, int m, int x, int y) {
        return x == 0 || x == n - 1 || y == 0 || y == m - 1;
    }
    void dfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid, bool &flag) {
        visited[i][j] = 1;

        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {1,0,-1,0};
        int delcol[] = {0,1,0,-1};

        if(checkBoundary(n, m, i, j)) {
            flag = false;
        }

        for(int k = 0; k < 4; k++) {
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];

            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && 
            visited[nrow][ncol] != 1 && grid[nrow][ncol] == 0) {
                dfs(nrow, ncol, visited, grid, flag);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();

       vector<vector<int>> visited(n, vector<int>(m, 0));

       for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 0 && visited[i][j] == 0) {
                bool flag = true;
                dfs(i, j, visited, grid, flag);
                if(flag) ans++;
            }
        }
    }
    return ans;
    }
};