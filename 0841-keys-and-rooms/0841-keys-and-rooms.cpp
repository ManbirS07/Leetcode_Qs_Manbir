class Solution {
public:
    void dfs(int u, vector<vector<int>>& rooms, vector<int>& visited) {
        visited[u] = 1;

        for(int &v: rooms[u]) {
            if(!visited[v]) {
                dfs(v, rooms, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //dfs ya bfs call me hi saare rooms visit hojane chahiye since we dont need to visit the rooms in order
        //since we can easily move back and forth from one room to another it gimmicks dfs
        int n = rooms.size();
        vector<int> visited(n, 0);

        dfs(0, rooms, visited);
        for(int x: visited) {
            if(x == 0) return false;
        }
        return true;
    }
};