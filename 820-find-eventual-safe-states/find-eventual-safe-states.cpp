class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis,
             vector<bool>& path, int curr, vector<int>& check) {

        vis[curr] = true;
        path[curr] = true;
        check[curr] = 0;

        for (int v : adj[curr]) {

            if (!vis[v]) {
                if (dfs(adj, vis, path, v, check))
                    return true;
            }
            else if (path[v]) {
                return true;
            }
            else if (check[v] == 0) {
                return true;
            }
        }

        check[curr] = 1;
        path[curr] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();

        vector<bool> vis(V, false);
        vector<bool> path(V, false);
        vector<int> check(V, 0);
        vector<int> safe;

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfs(graph, vis, path, i, check);
        }

        for (int i = 0; i < V; i++) {
            if (check[i] == 1)
                safe.push_back(i);
        }

        return safe;
    }
};