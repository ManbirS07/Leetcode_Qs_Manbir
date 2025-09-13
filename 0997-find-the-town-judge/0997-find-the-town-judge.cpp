class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //indegree of judge is n - 1 and outdegree of judge is 0
        vector<int> indegree(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        for(auto &edge: trust) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        for(int i = 1; i <= n; i++) {
            if(indegree[i] == n - 1) {
                if(adj[i].empty()) return i;
            }
        }
        return -1;
    }
};