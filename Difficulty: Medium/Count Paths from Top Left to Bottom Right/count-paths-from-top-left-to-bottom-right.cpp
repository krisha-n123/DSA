class Solution {
  public:
  vector<vector<int>> dp;
    int dfs(int i, int j,int m , int n){
        
        if(m-1==i && n-1==j){
            return 1;
        }
        if(i>=m || i<0 || j>=n || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=dfs(i+1,j,m,n)+dfs(i,j+1,m,n);
        return dp[i][j];
    }
    int numberOfPaths(int m, int n) {
        // code here
        dp.assign(m, vector<int> (n,-1));
        return dfs(0,0,m,n);
    }
};
