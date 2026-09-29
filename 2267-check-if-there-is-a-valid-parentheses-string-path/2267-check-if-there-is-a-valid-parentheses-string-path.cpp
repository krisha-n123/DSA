class Solution {
    int memo[105][105][205];

    bool solve(int r, int c, int count, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        count += (grid[r][c] == '(') ? 1 : -1;

        if (count < 0) return false;

        int remainingSteps = (n - 1 - r) + (m - 1 - c);
        if (count > remainingSteps) return false;

        if (r == n - 1 && c == m - 1) {
            return count == 0;
        }

        if (memo[r][c][count] != -1) return memo[r][c][count];

        bool down = false, right = false;
        if (r + 1 < n) down = solve(r + 1, c, count, grid);
        if (c + 1 < m) right = solve(r, c + 1, count, grid);

        return memo[r][c][count] = (down || right);
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if ((n + m - 1) % 2 != 0) return false;

        memset(memo, -1, sizeof(memo));
        return solve(0, 0, 0, grid);
    }
};