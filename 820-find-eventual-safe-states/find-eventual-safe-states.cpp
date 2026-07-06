class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& state, int i) {
        //1 visiting chances of unsafe 
        //2 safe 
        if (state[i] == 1)
            return false;
        if(state[i] == 2)
            return true;

        state[i]=1;

        for (int node : graph[i]) {
            if(!dfs(graph, state, node)) return false;
        }
        state[i] = 2;
            return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        vector<int> state(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++) {
            if(dfs(graph, state, i)){
                ans.push_back( i);
            }
        }
        return ans;
    }
};