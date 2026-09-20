class Solution {
  public:
    int largestSubsquare(vector<vector<char>> &mat) {
        // code here
        int n = mat.size();

                vector<vector<int>> right(n, vector<int>(n));
                vector<vector<int>> down(n, vector<int>(n));

                for (int i = n - 1; i >= 0; i--) {
                    for (int j = n - 1; j >= 0; j--) {
                        if (mat[i][j] == 'X') {
                            right[i][j] = 1;
                            down[i][j] = 1;

                            if (j + 1 < n)
                                right[i][j] += right[i][j + 1];

                            if (i + 1 < n)
                                down[i][j] += down[i + 1][j];
                        }
                    }
                }

                int ans = 0;

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int size = min(right[i][j], down[i][j]);

                        while (size > ans) {
                            int bottom = i + size - 1;
                            int rightCol = j + size - 1;

                            if (bottom < n && rightCol < n &&
                                right[bottom][j] >= size &&
                                down[i][rightCol] >= size) {
                                ans = size;
                                break;
                            }

                            size--;
                        }
                    }
                }

                return ans;
    }
};