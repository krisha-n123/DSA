class Solution {
  public:
    void Bfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int i, int j,vector<pair<int,int>>& shape){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=true;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int r=node.first;
            int c=node.second;
            
            shape.push_back({r-i, c-j});
            

            // Up
        if(r-1>=0 && grid[r-1][c]=='L' && !vis[r-1][c]) {
            q.push({r-1,c});
            vis[r-1][c]=true;
        }

        // Down
        if(r+1<grid.size() && grid[r+1][c]=='L' && !vis[r+1][c]) {
            q.push({r+1,c});
            vis[r+1][c]=true;
        }

        // Left
        if(c-1>=0 && grid[r][c-1]=='L' && !vis[r][c-1]) {
            q.push({r,c-1});
            vis[r][c-1]=true;
        }

        // Right
        if(c+1<grid[0].size() && grid[r][c+1]=='L' && !vis[r][c+1]) {
            q.push({r,c+1});
            vis[r][c+1]=true;
        }
        }
        return;


    }
    int countDistinctIslands(vector<vector<char>>& grid) {
        // code here
        int count=0;
        int v=grid.size();
        int u=grid[0].size();
        vector<vector<bool>> vis(v, vector<bool>(u, false));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<v;i++){
            for(int j=0;j<u;j++){
                if(grid[i][j]=='L' && !vis[i][j]){
                    count++;
                    vector<pair<int,int>> shape;
                    Bfs(grid, vis, i, j, shape);
                    st.insert(shape);
                }
            }
        }
        return st.size();
        
    }
};
