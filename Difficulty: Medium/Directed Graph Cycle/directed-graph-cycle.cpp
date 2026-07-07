class Solution {
  public:

    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<bool> vis(V, false);
        int ans=0;
        vector<vector<int>> adj(V);
        
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        
        vector<int> indegree(V, 0);
        for(int i=0;i<V;i++){
            for(int x : adj[i]){
                indegree[x]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans++;
            for(int it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return ans<V?true:false;
        
        
    }
};