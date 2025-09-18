class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int swimInWater(vector<vector<int>>& grid) {
        //minimize the maximum value
        //same concept as min path effort
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> time(n, vector<int>(m, 1e9));
        int delrow[] = {0,-1,0,1};
        int delcol[] = {1, 0, -1, 0};
        vector<vector<int>> visited(n, vector<int>(m, 0));
        time[0][0] = grid[0][0];

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = 1;
        while(!pq.empty()) {
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == n - 1 && col == m - 1) return dist;

            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    if(!visited[nrow][ncol]) {
                        int maxdist = max(dist, grid[nrow][ncol]);
                        if(time[nrow][ncol] > maxdist) time[nrow][ncol] = maxdist;

                        pq.push({maxdist, {nrow, ncol}});
                        visited[nrow][ncol] = 1;
                    }
                }
            }
        }
        return -1;
    }
};