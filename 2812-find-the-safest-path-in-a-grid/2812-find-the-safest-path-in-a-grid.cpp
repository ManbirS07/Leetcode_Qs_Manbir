class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        //maximize the minimum manahattan distance
        //dijkstra or BFS with BS
        int n = grid.size();
        int m = grid[0].size();
        //first, multisource bfs to calculate safe distance for each cell
        vector<vector<int>> safeDistance(n, vector<int>(m, -1));
        queue<p> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    q.push({0, {i, j}});
                    safeDistance[i][j] = 0;
                }
            }
        }
        int delrow[4] = {0, -1, 1, 0};
        int delcol[4] = {1, 0, 0, -1};

        while(!q.empty()) {
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 0) {
                    if(safeDistance[nrow][ncol] != -1) continue;
                    safeDistance[nrow][ncol] = dist + 1;
                    q.push({dist + 1, {nrow, ncol}});
                }
            }
        }

        //now, in safeDistance matrix, we have to maximize the min manhattan distance
        //max heap
        priority_queue<p, vector<p>> pq;
        pq.push({safeDistance[0][0], {0, 0}});
        vector<vector<int>> minManhatDistance(n, vector<int>(m, INT_MIN)); //min manhattan distance till each node
        while(!pq.empty()) {
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == n - 1 && col == m - 1) return dist;

            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && ncol >= 0 && ncol < m && nrow < n) {
                    int minManhattanDistance = min(dist, safeDistance[nrow][ncol]);
                    //maximize it
                    if(minManhattanDistance > minManhatDistance[nrow][ncol]) {
                        minManhatDistance[nrow][ncol] = minManhattanDistance;
                        pq.push({minManhattanDistance, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};