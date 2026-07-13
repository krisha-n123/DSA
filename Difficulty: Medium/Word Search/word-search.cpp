class Solution {
  public:
    int n,m;
    int dr[4]={-1,0,+1,0};
    int dc[4]={0,+1,0,-1};
    
    bool dfs(vector<vector<char>> &mat, string &word, int i, int j, int idx){
        if(idx==word.size()){
            return true;
        }
            
        if(i<0 || j<0 || i>=n || j>=m || mat[i][j]=='#') return false;
        
        if(mat[i][j]!=word[idx]){
            return false;
        }
        char temp=mat[i][j];
        
        mat[i][j]='#';
        
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(dfs(mat, word, nr, nc, idx+1)) return true;
        }
        mat[i][j]=temp;
        
        return false;
    }
    
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        n=mat.size();
        m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(dfs(mat, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};