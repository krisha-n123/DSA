class Solution {
  public:
    int n,m;
    vector<int> dr={+1,0,-1,0};
    vector<int> dc={0,+1,0,-1};
    int dfs(vector<vector<int>>& mat, vector<vector<int>>& vis, int xs, int ys, int xd, int yd){
        if(xs==xd && ys==yd){
            return 0;
            
        }
        vis[xs][ys]=1;
        
        int ans=-1;
        for(int i=0;i<4;i++){
            int nr = xs + dr[i];
            int nc = ys + dc[i]; 
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && mat[nr][nc]){
                vis[nr][nc]=1;
                int len=dfs(mat, vis, nr,nc, xd, yd);
                
                if(len!=-1){
                    ans=max(ans, len+1);
                }
                vis[nr][nc]=0;
            }
            
            
        }
        vis[xs][ys] = 0;
        return ans;
    }
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        // code here
        n=mat.size();
        m=mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        return dfs(mat, vis, xs,ys,xd,yd);
        
        
    }
};