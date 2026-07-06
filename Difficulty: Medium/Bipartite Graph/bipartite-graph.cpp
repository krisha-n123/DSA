class Solution {
  public:
    bool dfs(vector<vector<int>>& graph,vector<int>& color , int i){
        // color[i]=
        for(int it : graph[i]){
            if(color[it]==-1){
                color[it]=!color[i];
                if (!dfs(graph, color, it))
                    return false;
            }else if(color[it]==color[i]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> graph(V);
        for(auto i: edges){
            int u= i[0];
            int v= i[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] != -1)
                continue;
            color[i]=0;
            if(!dfs(graph, color, i)){
                return false;
            }
            
        }
        return true;
    }
};