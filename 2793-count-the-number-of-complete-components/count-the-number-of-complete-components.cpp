class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjlist(n);
        for (auto e : edges) {
            adjlist[e[0]].push_back(e[1]);
            adjlist[e[1]].push_back(e[0]);
        }
        int ans = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (vis[i])
                continue;
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            int nodescount = 0;
            int edgecount = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                nodescount++;

                edgecount += adjlist[node].size();
                for (int e : adjlist[node]) {
                    if (!vis[e]) {
                        q.push(e);
                        vis[e] = 1;
                    }
                }
            }
            int isequal = nodescount * (nodescount - 1) / 2;
            if (edgecount/2 == isequal)
                ans++;
        }
        return ans;
    }
};