class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        visited[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {0,1,-1,0};
        int delcol[] = {1,0,0,-1};

        int area = 1;
        for(int k = 0; k < 4; k++) {
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                if(!visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                    area += dfs(nrow, ncol, grid, visited);
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    ans = max(ans, dfs(i, j, grid, visited));
                }
            }
        }
        return ans;
    }
};
