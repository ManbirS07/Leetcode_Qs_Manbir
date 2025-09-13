class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n); 
        //time atleast utna toh lagega jitna jo max time h kisi bhi leaf node tak pohochne ka i.e last level of the employee ke pohochne tak ka

        for(int u = 0; u < n; u++) {
            int v = manager[u];
            if(v == -1) {
                continue;
            }
            adj[v].push_back(u); //manager -> employee mapping
        }
        vector<int> visited(n, 0);
        queue<pair<int, int>> q; //{node, time needed to inform till here}
        q.push({headID, 0});
        int ans = 0; //incase of only manager

        while(!q.empty()) {
            int u = q.front().first;
            int time = q.front().second;
            visited[u] = 1;
            q.pop();

            ans = max(ans, time);
            for(int &v: adj[u]) {
                if(!visited[v]) {
                    q.push({v, time + informTime[u]});
                }
            }
        }
        return ans;
    }
};