class Solution {
  public:
    int n, m;
    int dr[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
    int dc[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j,
             int& area) {
        if ((i < 0 || i >= n || j < 0 || j >= m || !grid[i][j] || vis[i][j]))
            return;
            area++;
        vis[i][j] = 1;
        for (int k = 0; k < 8; k++) {
            dfs(grid, vis, i + dr[k], j + dc[k], area );
        }
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans = 0;
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int area = 0;
                if (grid[i][j] && !vis[i][j]) {
                    dfs(grid, vis, i, j, area);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};