class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int dr[4] = {-1, 0, +1, 0};
    int dc[4] = {0, +1, 0, -1};
    int empcell=0;
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j,int cnt) {
        if ((i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == -1 || vis[i][j]))
            return 0;
        if (grid[i][j] == 2 )
            return cnt==empcell?1:0;
        
        // if (dp[i][j] != -1)
        //     return dp[i][j];
        int ans = 0;
        
        vis[i][j]=1;
        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() &&
                grid[nr][nc] != -1 && !vis[nr][nc]) {
                // vis[nr][nc]=1;
                ans += dfs(grid, vis, nr, nc,cnt+1);
                // vis[nr][nc]=0;
            }
        }
        vis[i][j]=0;

        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n, vector<int>(m, -1));
        int str = 0, stc = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    str = i;
                    stc = j;
                    
                }
                if(grid[i][j]!=-1){
                    empcell+=1;
                }
            }
        }
        return dfs(grid, vis, str, stc,1);
    }
};