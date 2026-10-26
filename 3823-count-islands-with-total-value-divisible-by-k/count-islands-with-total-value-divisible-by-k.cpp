class Solution {
public:
    long long Bfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=true;
        long long sum=grid[i][j];
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int r=node.first;
            int c=node.second;

            // Up
        if(r-1>=0 && grid[r-1][c] && !vis[r-1][c]) {
            q.push({r-1,c});
            sum+=grid[r-1][c];
            vis[r-1][c]=true;
        }

        // Down
        if(r+1<grid.size() && grid[r+1][c] && !vis[r+1][c]) {
            q.push({r+1,c});
            sum+=grid[r+1][c];
            vis[r+1][c]=true;
        }

        // Left
        if(c-1>=0 && grid[r][c-1] && !vis[r][c-1]) {
            q.push({r,c-1});
            sum+=grid[r][c-1];
            vis[r][c-1]=true;
        }

        // Right
        if(c+1<grid[0].size() && grid[r][c+1] && !vis[r][c+1]) {
            q.push({r,c+1});
            sum+=grid[r][c+1];
            vis[r][c+1]=true;
        }
        }
        return sum;


    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int count=0;
        int v=grid.size();
        int u=grid[0].size();
        vector<vector<bool>> vis(v, vector<bool>(u, false));

        for(int i=0;i<v;i++){
            for(int j=0;j<u;j++){
                if(grid[i][j] && !vis[i][j]){
                    
                    long long sum=Bfs(grid, vis, i, j);
                    if(sum%k==0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};