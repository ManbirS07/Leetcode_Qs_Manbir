class Solution {
public:
    typedef pair<int, pair<int,int>> p;
    int minimumEffortPath(vector<vector<int>>& grid) {
        //the first thought i get -> dp
        //since we need to check for effort in any path and out of those, select the path with min effort
        
        //mujhe source se destination jana h
        //source se har cell ka jaise pehle min distance store krta tha, issbari effort store karunga
        //kabhi bhi agar mujhe milta h ki effort mere curr effort se kam h, usse mai curr effort hi rakhunga kyuki jiss path se aaya hu, uska effort max h 
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<int>> effort(n, vector<int>(m, 1e9));
        effort[0][0] = 0;
        pq.push({0,{0, 0}});

        int delrow[] = {0, -1, 1, 0};
        int delcol[] = {1, 0, 0, -1};

        while(!pq.empty()) {
            int currdiff = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            for(int k = 0; k < 4; k++) {
                int nrow = i + delrow[k];
                int ncol = j + delcol[k];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                    int diff = abs(grid[nrow][ncol] - grid[i][j]);
                    int maxdiff = max(currdiff, diff); //maxdiff abhi tak ka max diff h aur isko maintain karke chalna h
                    if(effort[nrow][ncol] > maxdiff) {
                        effort[nrow][ncol] = maxdiff;
                        pq.push({maxdiff, {nrow, ncol}}); //iss cell tak ka effort = maxdiff jo maintain karke chalna h
                    }
                }
            }
        }

        return effort[n-1][m-1];
    }
};