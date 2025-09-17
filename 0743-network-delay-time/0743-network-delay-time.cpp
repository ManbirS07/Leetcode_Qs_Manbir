class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for(int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> distance(n + 1, 1e9);

        distance[k] = 0;
        distance[0] = 0;
        pq.push({0, k}); 
        while(!pq.empty()) {
            int wt = pq.top().first; //iss node tak pohochne ka min distance
            int u = pq.top().second;
            pq.pop();

            for(pair<int,int> &p: adj[u]) {
                int v = p.first; //u se mai v jaa skta hu via distance wt(u tak pohochne ka) + u se v ka distance jo h dist
                int dist = p.second;

                if(distance[v] > dist + wt) {
                    distance[v] = dist + wt;
                    pq.push({dist + wt, v});
                }
            }
        }
        int ans = -1;
        for(int x: distance) {
            if(x == 1e9) return -1;
            ans = max(ans, x);
        }
        return ans;
    }
};