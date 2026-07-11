class Solution {
public:
    int n,m;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& mat, int r, int c){
        int len=1;
        if(dp[r][c]!=-1){
            len = max(len, dp[r][c]);
            return len;
        }
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]>mat[r][c]){
                len=max(len, dfs(mat,nr,nc)+1);
            }
        }
        dp[r][c]=len;
        return len;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        dp.assign(n,vector<int>(m,-1));
        int ans=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans, dfs(mat, i, j));
            }
        }
        return ans;
    }
};