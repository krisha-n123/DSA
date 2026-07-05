class Solution {
public:
    int delr[4] = {-1, 0, +1, 0};
    int delc[4] = {0, +1, 0, -1};

    void bfs(vector<vector<int>>& grid, int r, int c) {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 0;
        int n = grid.size();
        int m = grid[0].size();
        while (!q.empty()) {
            auto node=q.front();
            q.pop();
            int tr=node.first;
            int tc=node.second;
            for (int i = 0; i < 4; i++) {
                int nr = tr + delr[i];
                int nc = tc + delc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == 1) {
                    q.push({nr, nc});
                    grid[nr][nc] = 0;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < m; i++) {
            // first row
            if (grid[0][i] == 1) {
                bfs(grid, 0, i);
            }
            // last row
            if (grid[n - 1][i] == 1) {
                bfs(grid, n - 1, i);
            }
        }
        for (int j = 0; j < n; j++) {
            // first col
            if (grid[j][0] == 1) {
                bfs(grid, j, 0);
            }

            // last col
            if (grid[j][m - 1]) {
                bfs(grid, j, m - 1);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};