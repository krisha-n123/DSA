class Solution {
public:
    void allCombination(vector<string>& ans, int open, int close, int n,
                        string s) {

        if (s.size() == n * 2) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            allCombination(ans, open + 1, close, n, s + '(');
        }
        if (close < open) {
            allCombination(ans, open, close + 1, n, s + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n == 0)
            return ans;
        int temp = n;
        allCombination(ans, 0, 0, n, "");
        return ans;
    }
};