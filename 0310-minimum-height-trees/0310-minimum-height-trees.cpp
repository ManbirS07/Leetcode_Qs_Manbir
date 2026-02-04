class Solution {
public:
    int maxHeight = 0;
    int dfs(int u, int prev, vector<vector<int>>& adj) {
        int height = 0;
        for(int v: adj[u]) {
            if(v == prev) continue;
            height = max(height, dfs(v, u, adj));
        }
        maxHeight = max(maxHeight, height);
        return 1 + height;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //concept used -> kisi bhi tree ki height min tab hogi jab it is routed at the middle nodes
        //leaf nodes -> the ones with indegree = 1
        //find all the middle nodes
        //if height of tree is odd, there is only one mid layer else there are 2 mid layers
        if(n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

            indegree[u]++;
            indegree[v]++;
        }
        dfs(0, -1, adj);

        vector<int> res;
        vector<int> visited(n, 0);
        queue<int> q; 
        //we'll start the traversal from all leaf nodes like toposort starts with all nodes with indegree 0
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 1) {
                q.push(i);
                visited[i] = 1;
            }

        }

        int levels = 0;
        int height1 = (maxHeight / 2);
        int height2 = (maxHeight % 2 == 0) ? 1 + height1: -1;

        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                int u = q.front();
                q.pop();

                if(levels == height1 || levels == height2) {
                    res.push_back(u);
                }

                for(int v: adj[u]) {
                    if(!visited[v]) {
                        q.push(v);
                        visited[v] = 1;
                    }
                }
            }
            levels++;
        }
        cout << maxHeight << endl;
        return res;
    }
};