class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans(n, ' ');
        int idx = 0;

        for (int i = 0; i < 26; i++) {
            int half = freq[i] / 2;

            while (half--) {
                ans[idx] = char('a' + i);
                ans[n - 1 - idx] = char('a' + i);
                idx++;
            }

            if (freq[i] % 2) {
                ans[n / 2] = char('a' + i);
            }
        }

        return ans;
    }
};