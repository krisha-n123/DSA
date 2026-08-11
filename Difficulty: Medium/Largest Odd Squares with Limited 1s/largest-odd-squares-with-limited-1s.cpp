class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries,
                              int k) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        // Prefix sum
        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pre[i + 1][j + 1] =
                    mat[i][j] + pre[i][j + 1] + pre[i + 1][j] - pre[i][j];
            }
        }

        auto getOnes = [&](int r1, int c1, int r2, int c2) {
            return pre[r2 + 1][c2 + 1]
                 - pre[r1][c2 + 1]
                 - pre[r2 + 1][c1]
                 + pre[r1][c1];
        };

        vector<int> ans;

        for (auto &q : queries) {
            int x = q[0], y = q[1];

            int maxRadius = min({x, y, n - 1 - x, m - 1 - y});

            int lo = 0, hi = maxRadius;
            int best = -1;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                int r1 = x - mid;
                int c1 = y - mid;
                int r2 = x + mid;
                int c2 = y + mid;

                int ones = getOnes(r1, c1, r2, c2);

                if (ones <= k) {
                    best = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            if (best == -1)
                ans.push_back(-1);
            else
                ans.push_back(2 * best + 1);
        }

        return ans;
    }
};