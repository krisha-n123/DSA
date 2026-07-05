class Solution {
public:
    int delr[4]={-1, 0 ,+1, 0};
    int delc[4]={0,+1, 0, -1};
    
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis, int r, int c){
        vis[r][c]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nr=r+delr[i];
            int nc=c+delc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                dfs(grid, vis, nr, nc);
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m , 0));
        for(int i=0;i<m;i++){
            //first row
            if(grid[0][i]==1 && !vis[0][i]){
                dfs(grid,vis, 0, i);
            }
            //last row
            if(grid[n-1][i]==1 && !vis[n-1][i]){
                dfs(grid,vis, n-1, i);
            }
        }
        for(int j=0;j<n;j++){
            //first col 
            if(grid[j][0]==1 && !vis[j][0]){
                dfs(grid, vis, j, 0);
            }
            
            // last col
            if(grid[j][m-1] && !vis[j][m-1]){
                dfs(grid, vis, j , m-1);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};