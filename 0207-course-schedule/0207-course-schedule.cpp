class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        //if no cyclic dependency we can complete the course
        vector<vector<int>> adj(n);
        for(auto &it: edges) {
        adj[it[0]].push_back(it[1]);
    }

    //using kahn's
    queue<int> q;
    vector<int> indegree(n, 0);
    for(int u = 0; u < n; u++) {
        for(int &v: adj[u]) {
            indegree[v]++;
        }
    }

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    int cnt = 0; //nodes with indegree = 0

    while(!q.empty()) {
        int node = q.front();
        cnt++;
        q.pop();

        for(int &v: adj[node]) {
            indegree[v]--;

            if(indegree[v] == 0) q.push(v);
        }
    }
    return cnt == n;
    }
};