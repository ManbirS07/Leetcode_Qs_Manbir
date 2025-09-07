class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        if(visited[i][j]) return;
        visited[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {0,1,-1,0};
        int delcol[] = {1,0,0,-1};

        for(int k = 0; k < 4; k++) {
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                if(!visited[nrow][ncol] && grid[nrow][ncol] == '1') {
                    dfs(nrow, ncol, grid, visited);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        //no of times dfs called?
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid, visited);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};