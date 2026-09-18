class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<string> ans;
        vector<int> first(26, n);
        vector<int> last(26, -1);
        for (int i = 0; i < n; i++) {
            int t = s[i] - 'a';
            first[t] = min(first[t], i);
            last[t] = i;
        }
        vector<vector<int>> intervals;
        for (int i = 0; i < n; i++) {
            int t = s[i] - 'a';
            if (first[t] != i) continue;
            bool isValid = true;
            int st = i;
            int ed = last[t];
            while (st <= ed) {
                int temp = s[st] - 'a';
                if (first[temp] < i) {
                    isValid = false;
                    break;
                } 
                ed = max(last[temp], ed);
                st++;
            }
            if (isValid) intervals.push_back({i, ed});
        }
        sort(intervals.begin(), intervals.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int prev = -1;
        for (int i = 0; i < intervals.size(); i++) {
            int f = intervals[i][0];
            int l = intervals[i][1];
            if (f > prev) {
                ans.push_back(s.substr(f, l - f + 1));
                prev = l;
            }
        }
        return ans;
    }
};