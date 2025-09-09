class Solution {
public:
    vector<int> parent;
    vector<int> rankv;

    // Find with path compression
    int find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
    }

    // Union by rank
    void Union(int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent) return;

    if (rankv[x_parent] > rankv[y_parent]) {
        parent[y_parent] = x_parent;
    } 
    else if (rankv[x_parent] < rankv[y_parent]) {
        parent[x_parent] = y_parent;
    } 
    else {
        parent[x_parent] = y_parent;
        rankv[y_parent]++;
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        //jitni bhi baar one computer has the same parent, it means they are connected
        //and in the same network
        //jitne bhi connected components h, har me se ek cable we can give

        //we need n - 1 edges to connect all n nodes
        if(connections.size() < n - 1) return -1;
        int extraEdges = 0, connComponents = 0;
        parent.resize(n);
        rankv.resize(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(auto &connection: connections) {
            int u = connection[0];
            int v = connection[1];

            int parentu = find(u);
            int parentv = find(v);

            if(parentu == parentv) {
                extraEdges++;
            } else {
                Union(u, v);
            }
        }

        for(int i = 0; i < n; i++) {
            if(parent[i] == i) connComponents++;
        }

        return connComponents - 1;
    }
};