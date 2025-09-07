class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        return true;
    }

    void dfs(vector<vector<int>>& image, int x, int y, int color, int n, int m, vector<vector<int>>& visited, int originalColor) {
        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, 1, 0, -1};
        if(visited[x][y]) return;
        visited[x][y] = 1; //visit karlia ye cell

        for(int i = 0; i < 4; i++) {
            int nrow = x + delrow[i];
            int ncol = y + delcol[i];

            if(isValid(nrow, ncol, n, m)) {
                if(!visited[nrow][ncol]) {
                    if(image[nrow][ncol] == originalColor) {
                        image[nrow][ncol] = color;
                        dfs(image, nrow, ncol, color, n, m, visited, originalColor);
                    }
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int originalColor = image[sr][sc];
        image[sr][sc] = color;

        dfs(image, sr, sc, color, n, m, visited, originalColor);
        return image;
    }
};