class Solution {
  public:
    
    bool dfs(vector<vector<int>>& adj, vector<bool> &vis, vector<bool>& path, int curr){
        vis[curr]=true;
        path[curr]=true;
        for(int v : adj[curr]){
            
            if(!vis[v]) {
                if(dfs(adj, vis, path, v))
                    return true;
            }else if(path[v]){
                return true;
            }        
            
        }
        path[curr] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<bool> vis(V, false);
        vector<bool> path(V, false);
        vector<vector<int>> adj(V);
        
        for(auto &e: edges){
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
        }
        for(int i=0;i<V;i++){
            if(!vis[i] && !path[i] && dfs(adj, vis,path, i)){
                return true;
            }
        }
        return false;
        
        
    }
};