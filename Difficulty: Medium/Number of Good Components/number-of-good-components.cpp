
class Solution {
  public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adjlist(v+1);
        for(auto e : edges){
            adjlist[e[0]].push_back(e[1]);
            adjlist[e[1]].push_back(e[0]);
        }
        
        vector<int> vis(v+1,0);
        int ans=0;
        for(int i=1;i<v+1;i++){
            if(vis[i]==1) continue;
            queue<int> q;
            q.push(i);
            vis[i]=1;
            int nodecount=0;
            int edgecount=0;
            
            while(!q.empty()){
                int node=q.front();
                q.pop();
                nodecount++;
                edgecount+=adjlist[node].size();
                for(int e: adjlist[node]){
                    if(!vis[e]){
                        vis[e]=1;
                        q.push(e);
                        
                    }
                }
            }
            int isequal=nodecount*(nodecount-1)/2;
            if(edgecount/2==isequal) ans++;
            
            
        }
        return ans;
    }
};
