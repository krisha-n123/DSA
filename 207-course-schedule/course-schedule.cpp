class Solution {
public:
    bool dfs(vector<vector<int>>& adj,vector<int>& vis,vector<int>& path, int i ){
        vis[i]=!vis[i];
        path[i]=!path[i];

        for(int v : adj[i]){
            if(!vis[v]){
                if(dfs(adj, vis, path, v)){
                    return true;
                }
            }else if(path[v]){
                return true;
            }
        }
        path[i]=0;
        return false;


    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int ans=0;
        int V=numCourses;
        vector<vector<int>> adj(V);
        for(auto e: prerequisites){
            adj[e[0]].push_back(e[1]);
        }
        vector<int> vis(numCourses, 0);
        vector<int> path(numCourses, 0);
        for(int i=0;i<V;i++){
            if(!vis[i] && !path[i] && dfs(adj , vis, path, i)){
                return false;
            }
        }
        
        return true;
        
    }
};