class Solution {
public:
    typedef long long ll;

    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // indegree, node
        //jiski indegree jitni zyada usko utni zyada value assign
        //n nodes, m edges
        vector<pair<int,int>> indegree(n, {0, 0});

        for (int i = 0; i < n; i++) {
            indegree[i].second = i;
        }

        for (auto &road : roads) { //O(m)
            int u = road[0];
            int v = road[1];
            indegree[u].first++;
            indegree[v].first++;
        }

        sort(indegree.begin(), indegree.end()); //nlogn

        vector<ll> valAssigned(n);
        ll val = n;

        for (int i = n - 1; i >= 0; i--) {
            int node = indegree[i].second;
            valAssigned[node] = val;
            val--;
        }

        ll sum = 0;
        for (auto &road : roads) {
            sum += (valAssigned[road[0]] + valAssigned[road[1]]);
        }

        return sum; //O(nlogn + m)
    }
};
