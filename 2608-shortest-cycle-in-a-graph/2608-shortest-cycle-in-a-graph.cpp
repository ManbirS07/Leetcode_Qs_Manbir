class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        //we will use bfs since we need to find the shortest distance
        //we need a parent array and a distance array -> that defines the distance of each node from the source node

        vector<vector<int>> adj(n);
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int ans = INT_MAX;
        //most imp concept -> we will do BFS from each node because we want to try each node as the source node and see if it can detect shorter cycles
        for(int i = 0; i < n; i++) {
            vector<int> dist(n, 1e9);
            vector<int> parent(n, -1);
            queue<int> q;
            dist[i] = 0; // i is the source node
            q.push(i);
        
            while(!q.empty()) {
                int u = q.front();
                q.pop();

                for(int v: adj[u]) {
                    if(dist[v] == 1e9){//works as unvisited 
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    } else if(v != parent[u])
                        { //if v != parent and still distance is not 1e9 -> cycle                  
                            ans = min(ans, dist[u] + dist[v] + 1);
                        }
                    
                }
            }
        }    
        return ans == INT_MAX ? -1: ans;  
    }
};