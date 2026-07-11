class Solution {
public:
    const int e = 1e9 + 7;
    int n,m;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,+1,0,-1};
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& grid , int r, int c){
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int ans=1;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]>grid[r][c]){
                ans=(ans+dfs(grid, nr,nc))%e;
            }
        }
        return dp[r][c]=ans%e;
    }
    int countPaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        dp.assign(n,vector<int>(m,-1));

        int path=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                path=(path + dfs(grid, i, j))%e;
            }
        }
        return path%e;

    }
};