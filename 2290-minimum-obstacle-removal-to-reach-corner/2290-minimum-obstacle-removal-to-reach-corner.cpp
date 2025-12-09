class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        priority_queue<p, vector<p>, greater<p>> q; 
        int delrow[4] = {0,-1,1,0};
        int delcol[4] = {1,0,0,-1};
        int startObstacle = grid[0][0] == 0 ? 0 : 1;

        q.push({startObstacle, {0, 0}});
        visited[0][0] = 1;
        while(!q.empty()) {
            auto [currObstacles, coordinates] = q.top();
            int row = coordinates.first;
            int col = coordinates.second;
            if(row == n - 1 && col == m - 1) {
                return currObstacles;
            }
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !visited[nrow][ncol]) {
                    int newObstacles = currObstacles;
                    if(grid[nrow][ncol] == 1) {
                        newObstacles++;
                    }
                    q.push({newObstacles, {nrow, ncol}});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        return -1;        
    }
};