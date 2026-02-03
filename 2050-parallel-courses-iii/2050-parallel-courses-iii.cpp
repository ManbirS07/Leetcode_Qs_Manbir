class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int minTime = 0;
        vector<int> indegree(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        vector<int> maxPrequisiteTime(n + 1, 0);

        for(auto &it: relations) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<pair<int, int>> q; //task, completion time
        for(int i = 1; i <= n; i++) {
            if(indegree[i] == 0) {
                q.push({i, time[i - 1]});
            }
        }

        //i need to take the max time of a pre-requisite, not add only when indegree becomes 0
        //I'll take a map and for each node, store the max time of it's pre-requisite
        //when that node's indegree becomes 0, the time it takes would be equal to it's own time + max pre-requisite time
        while(!q.empty()) {
            int u = q.front().first; //u has been completed
            int completionTimeU = q.front().second;
            minTime = max(minTime, completionTimeU);
            q.pop();

            for(int v: adj[u]) {
                indegree[v]--;
                maxPrequisiteTime[v] = max(maxPrequisiteTime[v], completionTimeU); //u is a pre-requisite of v
                // cout << v <<  " " << maxPrequisiteTime[v] << endl;
                if(indegree[v] == 0) {
                    int completionTimeV = time[v - 1]; //0 based indexing
                    q.push({v, maxPrequisiteTime[v] + completionTimeV});
                }
            }
        }
        return minTime;
    }
};