class Solution {
  public:
  int n, m;
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& grid, int i , int j){
        if((i<0 || i>=n || j<0 || j>=m || grid[i][j]==1)) return 0;

        if(i==n-1 && j==m-1) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=dfs(grid, i+1,j)+dfs(grid, i,j+1);
    }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        n= grid.size();
       m= grid[0].size();
       dp.assign(n, vector<int>(m,-1));
       return dfs(grid, 0,0);  
    }
};