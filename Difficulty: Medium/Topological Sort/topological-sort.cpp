class Solution {
  public:
    void dfs(vector<vector<int>>& edges, vector<int>& vis, stack<int>& s, int node){
        vis[node]=1;
        for(int i : edges[node]){
            if(!vis[i]){
                dfs(edges, vis, s, i);
            }
        }
        s.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> vis(V, 0);
        stack<int> s;
        vector<int> ans;
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj, vis, s, i);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
        
    }
};